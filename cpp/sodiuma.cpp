#include "sodiuma.h"
#include "sodiuma_ho.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

void Install(facebook::jsi::Runtime &runtime) {
  if (sodium_init() < 0) {
    throw std::runtime_error{"Failed to initialize sodium"};
  }

  const auto sodiumaHostObject = facebook::jsi::Object::createFromHostObject(
      runtime, std::make_shared<SodiumaHostObject>());
  runtime.global().setProperty(runtime, "__s77rt__sodiuma",
                               std::move(sodiumaHostObject));
}

} // namespace sodiuma
} // namespace s77rt
