#include "sodiuma.h"
#include "randombytes/randombytes.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value Sodiuma::get(facebook::jsi::Runtime &runtime,
                                  const facebook::jsi::PropNameID &name) {
  const std::string property_name = name.utf8(runtime);

  if (property_name == "randombytes_random") {
    return facebook::jsi::Function::createFromHostFunction(
        runtime,
        facebook::jsi::PropNameID::forAscii(runtime, "randombytes_random"), 0,
        RandombytesRandom);
  }

  if (property_name == "randombytes_uniform") {
    return facebook::jsi::Function::createFromHostFunction(
        runtime,
        facebook::jsi::PropNameID::forAscii(runtime, "randombytes_uniform"), 1,
        RandombytesUniform);
  }

  if (property_name == "randombytes_buf") {
    return facebook::jsi::Function::createFromHostFunction(
        runtime,
        facebook::jsi::PropNameID::forAscii(runtime, "randombytes_buf"), 2,
        RandombytesBuf);
  }

  if (property_name == "randombytes_buf_deterministic") {
    return facebook::jsi::Function::createFromHostFunction(
        runtime,
        facebook::jsi::PropNameID::forAscii(runtime,
                                            "randombytes_buf_deterministic"),
        3, RandombytesBufDeterministic);
  }

  if (property_name == "randombytes_close") {
    return facebook::jsi::Function::createFromHostFunction(
        runtime,
        facebook::jsi::PropNameID::forAscii(runtime, "randombytes_close"), 0,
        RandombytesClose);
  }

  if (property_name == "randombytes_stir") {
    return facebook::jsi::Function::createFromHostFunction(
        runtime,
        facebook::jsi::PropNameID::forAscii(runtime, "randombytes_stir"), 0,
        RandombytesStir);
  }

  return facebook::jsi::Value::undefined();
}

std::vector<facebook::jsi::PropNameID>
Sodiuma::getPropertyNames(facebook::jsi::Runtime &runtime) {
  return facebook::jsi::PropNameID::names(
      runtime, "randombytes_random", "randombytes_uniform", "randombytes_buf",
      "randombytes_buf_deterministic", "randombytes_close", "randombytes_stir");
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
