#include "uinput.h"
extern "C" {
	#include <libevdev/libevdev.h>
	#include <libevdev/libevdev-uinput.h>
}
#include <cstring>
#include <sstream>
#include <map>


static std::map<int, struct libevdev_uinput*> devices;


static void
throwLibevdevError(Napi::Env env, const char *function, int err)
{
	std::ostringstream message;
	message << function << " (errno " << -err << ") error: " << strerror(-err);
	throw Napi::Error::New(env, message.str());
}

static int
getNumber(Napi::Env env, const Napi::Object &object, const char *key)
{
	Napi::Value value = object.Get(key);
	if (!value.IsNumber()) {
		std::ostringstream message;
		message << key << " must be a number";
		throw Napi::Error::New(env, message.str());
	}
	return value.As<Napi::Number>().Int32Value();
}


static void
configureDevice(Napi::Env env, struct libevdev *dev, const Napi::Object &options)
{
	if (options.Has("name")) {
		Napi::Value value = options.Get("name");
		if (!value.IsString()) { throw Napi::Error::New(env, "name must be a string"); }
		std::string name = value.As<Napi::String>().Utf8Value();
		libevdev_set_name(dev, name.c_str());
	}

	if (options.Has("bustype")) { libevdev_set_id_bustype(dev, getNumber(env, options, "bustype")); }
	if (options.Has("vendor")) { libevdev_set_id_vendor(dev, getNumber(env, options, "vendor")); }
	if (options.Has("product")) { libevdev_set_id_product(dev, getNumber(env, options, "product")); }
	if (options.Has("version")) { libevdev_set_id_version(dev, getNumber(env, options, "version")); }

	if (options.Has("props")) {
		Napi::Value value = options.Get("props");
		if (!value.IsArray()) { throw Napi::Error::New(env, "props must be an array"); }
		Napi::Array props = value.As<Napi::Array>();
		for (unsigned i = 0; i < props.Length(); i++) {
			Napi::Value item = props.Get(i);
			if (!item.IsNumber()) { throw Napi::Error::New(env, "props must be an array of numbers"); }
			libevdev_enable_property(dev, item.As<Napi::Number>().Int32Value());
		}
	}

	if (!options.Has("events")) { return; }

	Napi::Value eventsValue = options.Get("events");
	if (!eventsValue.IsArray()) { throw Napi::Error::New(env, "events must be an array"); }
	Napi::Array events = eventsValue.As<Napi::Array>();
	for (unsigned i = 0; i < events.Length(); i++) {
		Napi::Value eventValue = events.Get(i);
		if (!eventValue.IsObject()) { throw Napi::Error::New(env, "events must be an array of objects"); }
		Napi::Object event = eventValue.As<Napi::Object>();
		int type = getNumber(env, event, "type");

		int err = libevdev_enable_event_type(dev, type);
		if (err != 0) { throwLibevdevError(env, "libevdev_enable_event_type", err); }

		Napi::Value codesValue = event.Get("codes");
		if (!codesValue.IsArray()) { throw Napi::Error::New(env, "codes must be an array"); }
		Napi::Array codes = codesValue.As<Napi::Array>();

		if (type != EV_ABS) {
			for (unsigned j = 0; j < codes.Length(); j++) {
				Napi::Value item = codes.Get(j);
				if (!item.IsNumber()) { throw Napi::Error::New(env, "codes must be an array of numbers"); }
				int code = item.As<Napi::Number>().Int32Value();

				err = libevdev_enable_event_code(dev, type, code, NULL);
				if (err != 0) { throwLibevdevError(env, "libevdev_enable_event_code", err); }
			}
		}
		else {
			for (unsigned j = 0; j < codes.Length(); j++) {
				Napi::Value item = codes.Get(j);
				if (!item.IsObject()) { throw Napi::Error::New(env, "EV_ABS codes must be an array of objects"); }
				Napi::Object abs = item.As<Napi::Object>();

				int code = getNumber(env, abs, "code");

				struct input_absinfo absinfo = {};
				absinfo.minimum = getNumber(env, abs, "min");
				absinfo.maximum = getNumber(env, abs, "max");
				if (abs.Has("resolution")) {
					absinfo.resolution = getNumber(env, abs, "resolution");
				}

				err = libevdev_enable_event_code(dev, type, code, &absinfo);
				if (err != 0) { throwLibevdevError(env, "libevdev_enable_event_code", err); }
			}
		}
	}
}

Napi::Value
uinput::createDevice(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	if (!info[0].IsObject()) { throw Napi::Error::New(env, "options must be an object"); }
	Napi::Object options = info[0].As<Napi::Object>();

	struct libevdev *dev = libevdev_new();

	struct libevdev_uinput *uidev;
	try {
		configureDevice(env, dev, options);

		int err = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev);
		if (err != 0) { throwLibevdevError(env, "libevdev_uinput_create_from_device", err); }
	}
	catch (...) {
		libevdev_free(dev);
		throw;
	}
	libevdev_free(dev);

	int fd = libevdev_uinput_get_fd(uidev);
	devices[fd] = uidev;

	const char *syspath = libevdev_uinput_get_syspath(uidev);

	const char *devnode = libevdev_uinput_get_devnode(uidev);

	Napi::Object result = Napi::Object::New(env);
	result.Set("fd", Napi::Number::New(env, fd));
	result.Set("syspath", syspath == nullptr ? env.Null() : Napi::String::New(env, syspath));
	result.Set("devnode", devnode == nullptr ? env.Null() : Napi::String::New(env, devnode));

	return result;
}


static struct libevdev_uinput *
getDevice(Napi::Env env, const Napi::CallbackInfo &info)
{
	if (!info[0].IsNumber()) { throw Napi::Error::New(env, "fd must be a number"); }
	int fd = info[0].As<Napi::Number>().Int32Value();

	auto it = devices.find(fd);
	if (it == devices.end()) {
		std::ostringstream message;
		message << "unknown device fd " << fd;
		throw Napi::Error::New(env, message.str());
	}
	return it->second;
}

Napi::Value
uinput::writeEvents(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	struct libevdev_uinput *uidev = getDevice(env, info);

	if (!info[1].IsArray()) { throw Napi::Error::New(env, "events must be an array"); }
	Napi::Array events = info[1].As<Napi::Array>();

	for (unsigned i = 0; i < events.Length(); i++) {
		Napi::Value item = events.Get(i);
		if (!item.IsObject()) { throw Napi::Error::New(env, "events must be an array of objects"); }
		Napi::Object event = item.As<Napi::Object>();
		unsigned type = getNumber(env, event, "type");
		unsigned code = getNumber(env, event, "code");
		int value = getNumber(env, event, "value");

		int err = libevdev_uinput_write_event(uidev, type, code, value);
		if (err != 0) { throwLibevdevError(env, "libevdev_uinput_write_event", err); }
	}

	return env.Undefined();
}


Napi::Value
uinput::destroyDevice(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	struct libevdev_uinput *uidev = getDevice(env, info);
	int fd = info[0].As<Napi::Number>().Int32Value();

	libevdev_uinput_destroy(uidev);
	devices.erase(fd);

	return env.Undefined();
}
