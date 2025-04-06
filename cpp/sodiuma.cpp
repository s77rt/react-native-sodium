#include "sodiuma.h"

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value Sodiuma::get(facebook::jsi::Runtime &runtime,
                                  const facebook::jsi::PropNameID &name) {
  const std::string property_name = name.utf8(runtime);

  if (auto property_constant = property_constants_.find(property_name);
      property_constant != property_constants_.end()) {

    if (property_constant->second.index() == 0) {
      return facebook::jsi::Value(
          static_cast<double>(std::get<0>(property_constant->second)));
    }

    return facebook::jsi::Value(facebook::jsi::String::createFromAscii(
        runtime, std::get<1>(property_constant->second)));
  }

  if (auto property_function = property_functions_.find(property_name);
      property_function != property_functions_.end()) {

    auto [func, func_length] = property_function->second;

    return facebook::jsi::Function::createFromHostFunction(
        runtime, facebook::jsi::PropNameID::forAscii(runtime, property_name),
        func_length, func);
  }

  return facebook::jsi::Value::undefined();
}

std::vector<facebook::jsi::PropNameID>
Sodiuma::getPropertyNames(facebook::jsi::Runtime &runtime) {
  std::vector<facebook::jsi::PropNameID> property_names;

  for (const auto &[key, _] : property_constants_) {
    property_names.push_back(facebook::jsi::PropNameID::forAscii(runtime, key));
  }

  for (const auto &[key, _] : property_functions_) {
    property_names.push_back(facebook::jsi::PropNameID::forAscii(runtime, key));
  }

  return property_names;
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
