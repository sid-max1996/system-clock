#include <napi.h>
#include "system_clock.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return system_clock::Init(env, exports);
}

NODE_API_MODULE(system_clock, InitAll)
