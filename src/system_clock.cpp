#include <windows.h>
#include "system_clock.h"

Napi::Boolean system_clock::setDateAndTime(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();

  if (info.Length() < 6) {
    Napi::TypeError::New(env, "Six params expected day, month, year, hour, minute, sec").ThrowAsJavaScriptException();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber() || !info[3].IsNumber() || !info[4].IsNumber() || !info[5].IsNumber()) {
    Napi::TypeError::New(env, "not a number param").ThrowAsJavaScriptException();
  } 

  Napi::Number day = info[0].As<Napi::Number>();
  Napi::Number month = info[1].As<Napi::Number>();
  Napi::Number year = info[2].As<Napi::Number>();
  Napi::Number hour = info[3].As<Napi::Number>();
  Napi::Number minute = info[4].As<Napi::Number>();
  Napi::Number sec = info[5].As<Napi::Number>();

  SYSTEMTIME st;
  st.wYear = year.Int32Value();
  st.wMonth = month.Int32Value();
  st.wDay = day.Int32Value();
  st.wHour = hour.Int32Value();
  st.wMinute = minute.Int32Value();
  st.wSecond = sec.Int32Value();
  st.wMilliseconds = 0;
  bool returnValue = SetSystemTime(&st);
  
  return Napi::Boolean::New(env, returnValue);
}

Napi::Boolean system_clock::setTimeZone(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "One param expected bias").ThrowAsJavaScriptException();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "bias not a number").ThrowAsJavaScriptException();
  } 

  Napi::Number bias = info[0].As<Napi::Number>();

  TIME_ZONE_INFORMATION ti;
  ti.Bias = bias.Int32Value();
  bool returnValue = SetTimeZoneInformation(&ti);
  
  return Napi::Boolean::New(env, returnValue);
}

Napi::Object system_clock::Init(Napi::Env env, Napi::Object exports) 
{
  exports.Set(
    "setDateAndTime", Napi::Function::New(env, system_clock::setDateAndTime)
  );

  // exports.Set(
  //   "setTimeZone", Napi::Function::New(env, system_clock::setTimeZone)
  // );

  return exports;
}
