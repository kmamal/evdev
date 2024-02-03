#include "uinput.h"
extern "C" {
	#include <libevdev/libevdev.h>
	#include <libevdev/libevdev-uinput.h>
}
#include <cstring>
#include <sstream>
#include <map>


static std::map<int, struct libevdev_uinput*> devices;
static int err = 0;


Napi::Value
uinput::createDevice(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	Napi::Object options = info[0].As<Napi::Object>();

	struct libevdev *dev = libevdev_new();

	if (options.Has("name")) {
		std::string name = options.Get("name").As<Napi::String>().Utf8Value();
		libevdev_set_name(dev, name.c_str());
	}

	if (options.Has("bustype")) {
		int bustype = options.Get("bustype").As<Napi::Number>().Int32Value();
		libevdev_set_id_bustype(dev, bustype);
	}

	if (options.Has("vendor")) {
		int vendor = options.Get("vendor").As<Napi::Number>().Int32Value();
		libevdev_set_id_vendor(dev, vendor);
	}

	if (options.Has("product")) {
		int product = options.Get("product").As<Napi::Number>().Int32Value();
		libevdev_set_id_product(dev, product);
	}

	if (options.Has("version")) {
		int version = options.Get("version").As<Napi::Number>().Int32Value();
		libevdev_set_id_version(dev, version);
	}

	if (options.Has("events")) {
		Napi::Array events = options.Get("events").As<Napi::Array>();
		for (unsigned i = 0; i < events.Length(); i++) {
			Napi::Object event = events.Get(i).As<Napi::Object>();
			int type = event.Get("type").As<Napi::Number>().Int32Value();
			libevdev_enable_event_type(dev, type);

			Napi::Array codes = event.Get("codes").As<Napi::Array>();
			for (unsigned j = 0; j < events.Length(); j++) {
				if (type != EV_ABS) {
					int code = codes.Get(j).As<Napi::Number>().Int32Value();
					libevdev_enable_event_code(dev, type, code, NULL);
				} else {
					Napi::Object abs = codes.Get(j).As<Napi::Object>();
					int code = abs.Get("code").As<Napi::Number>().Int32Value();
					int min = abs.Get("min").As<Napi::Number>().Int32Value();
					int max = abs.Get("max").As<Napi::Number>().Int32Value();
					struct input_absinfo min_max = {};
					min_max.minimum = min;
					min_max.maximum = max;
					libevdev_enable_event_code(dev, type, code, &min_max);
				}
			}
		}
	}

	struct libevdev_uinput *uidev;
	err = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev);
	if (err != 0) {
			std::ostringstream message;
			message << "libevdev_uinput_create_from_device (errno " << -err << ") error: " << strerror(-err);
			err = 0;
			throw Napi::Error::New(env, message.str());
	}

	// libevdev_free(dev);

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


Napi::Value
uinput::writeEvents(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int fd = info[0].As<Napi::Number>().Int32Value();
	struct libevdev_uinput* uidev = devices[fd];

	Napi::Array events = info[1].As<Napi::Array>();

	for (unsigned i = 0; i < events.Length(); i++) {
		Napi::Object event = events.Get(i).As<Napi::Object>();
		unsigned type = event.Get("type").As<Napi::Number>().Int32Value();
		unsigned code = event.Get("code").As<Napi::Number>().Int32Value();
		int value = event.Get("value").As<Napi::Number>().Int32Value();

		err = libevdev_uinput_write_event(uidev, type, code, value);
		if (err != 0) {
				std::ostringstream message;
				message << "libevdev_uinput_write_event (errno " << -err << ") error: " << strerror(-err);
				err = 0;
				throw Napi::Error::New(env, message.str());
		}
	}

	return env.Undefined();
}


Napi::Value
uinput::destroyDevice(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int fd = info[0].As<Napi::Number>().Int32Value();
	struct libevdev_uinput* uidev = devices[fd];

	libevdev_uinput_destroy(uidev);

	return env.Undefined();
}
