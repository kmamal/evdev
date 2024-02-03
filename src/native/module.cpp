#include <napi.h>

#include "enums.h"
#include "global.h"
#include "uinput.h"


Napi::Object
init (Napi::Env env, Napi::Object exports)
{
	exports.Set("enums_get", Napi::Function::New<enums::get>(env));

	exports.Set("global_initialize", Napi::Function::New<global::initialize>(env));
	exports.Set("global_cleanup", Napi::Function::New<global::cleanup>(env));

	exports.Set("uinput_createDevice", Napi::Function::New<uinput::createDevice>(env));
	exports.Set("uinput_writeEvents", Napi::Function::New<uinput::writeEvents>(env));
	exports.Set("uinput_destroyDevice", Napi::Function::New<uinput::destroyDevice>(env));

	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init)
