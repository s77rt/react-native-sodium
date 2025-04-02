#include "sodiuma.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

Sodiuma::~Sodiuma() {}

facebook::jsi::Value Sodiuma::get(facebook::jsi::Runtime &,
                                  const facebook::jsi::PropNameID &name) {
  return facebook::jsi::Value(5);
}

void Sodiuma::set(facebook::jsi::Runtime &,
                  const facebook::jsi::PropNameID &name,
                  const facebook::jsi::Value &value) {
  return;
}

std::vector<facebook::jsi::PropNameID>
Sodiuma::getPropertyNames(facebook::jsi::Runtime &rt) {
  std::vector<facebook::jsi::PropNameID> result;
  return result;
}

void Install(facebook::jsi::Runtime &runtime) {
  if (sodium_init() < 0) {
    throw std::runtime_error{"Failed to initialize sodium"};
  }

  runtime.global().setProperty(runtime, "__s77rt__sodiuma",
                               facebook::jsi::Object::createFromHostObject(
                                   runtime, std::make_shared<Sodiuma>()));
}

} // namespace sodiuma
} // namespace s77rt
