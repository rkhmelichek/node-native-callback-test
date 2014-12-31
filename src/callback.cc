#include <v8.h>
#include <node.h>
using namespace v8;
using namespace node;

void CallFuncViaCall(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  printf("%s: START\n", __func__);
  Local<Object> obj = Local<Object>::Cast(args[0]);
  Local<Function> cb = obj->Get(String::NewFromUtf8(isolate, "cb")).As<Function>();
  cb->Call(obj, 0, NULL);
  printf("%s: END\n", __func__);
}

void CallFuncViaMakeCallback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  printf("%s: START\n", __func__);
  Local<Object> obj = Local<Object>::Cast(args[0]);
  MakeCallback(isolate, obj, "cb", 0, NULL);
  printf("%s: END\n", __func__);
}

void InitAll(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(exports, "callFuncViaCall", CallFuncViaCall);
  NODE_SET_METHOD(exports, "callFuncViaMakeCallback", CallFuncViaMakeCallback);
}

NODE_MODULE(callback, InitAll)
// When building as a built-in node.js module.
//NODE_MODULE_CONTEXT_AWARE_BUILTIN(callback, InitAll)