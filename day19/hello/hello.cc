/**
 * Created by gbox3d on 15. 5. 18..
 */

#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(
  String::NewFromUtf8(isolate, "hello"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports,
  "getHello", //js 측에서 호출하는 함수이름 지정.
  Method);
}

NODE_MODULE(addon, init)

}  // namespace demo