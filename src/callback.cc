#include <v8.h>
#include <node.h>
#include <nan.h>
using namespace v8;
using namespace node;

NAN_METHOD(CallFuncViaCall) {
  NanScope();

  printf("%s: START\n", __func__);
  Local<Object> obj = Local<Object>::Cast(args[0]);
  Local<Function> cb = obj->Get(NanNew("cb")).As<Function>();
  cb->Call(obj, 0, NULL);
  printf("%s: END\n", __func__);
  
  NanReturnUndefined();
}

NAN_METHOD(CallFuncViaMakeCallback) {
  NanScope();

  printf("%s: START\n", __func__);
  Local<Object> obj = Local<Object>::Cast(args[0]);
  NanMakeCallback(obj, "cb", 0, NULL);
  printf("%s: END\n", __func__);
  
  NanReturnUndefined();
}

void InitAll(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(exports, "callFuncViaCall", CallFuncViaCall);
  NODE_SET_METHOD(exports, "callFuncViaMakeCallback", CallFuncViaMakeCallback);
}

NODE_MODULE(callback, InitAll)
// When building as a built-in node.js module.
//NODE_MODULE_CONTEXT_AWARE_BUILTIN(callback, InitAll)