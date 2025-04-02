#include "sodiuma.h"
#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value Add(facebook::jsi::Runtime &runtime,
                         const facebook::jsi::Value &thisValue,
                         const facebook::jsi::Value *arguments, size_t count) {
  double result = arguments[0].asNumber() + arguments[1].asNumber();
  return facebook::jsi::Value(result);
}

void Install(facebook::jsi::Runtime &runtime) {
  const auto add = facebook::jsi::Function::createFromHostFunction(
      runtime, facebook::jsi::PropNameID::forAscii(runtime, "add"), 2, Add);

  runtime.global().setProperty(runtime, "__ExampleJSIAdd", std::move(add));
}

} // namespace sodiuma
} // namespace s77rt
