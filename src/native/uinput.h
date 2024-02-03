#ifndef _UINPUT_H_
#define _UINPUT_H_

#include <napi.h>

namespace uinput {

	Napi::Value createDevice(const Napi::CallbackInfo &info);
	Napi::Value writeEvents(const Napi::CallbackInfo &info);
	Napi::Value destroyDevice(const Napi::CallbackInfo &info);

}; // namespace uinput

#endif // _UINPUT_H_
