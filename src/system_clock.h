#include <napi.h>

namespace system_clock {
  Napi::Boolean setDateAndTime(const Napi::CallbackInfo& info);
  Napi::Boolean setTimeZone(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
}
