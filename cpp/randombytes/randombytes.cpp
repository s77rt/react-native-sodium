#include "randombytes.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value RandombytesRandom(facebook::jsi::Runtime &runtime,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *,
                                       size_t count) {
  if (count != 0) {
    throw facebook::jsi::JSError(
        runtime, "Incorrect number of arguments. Expected 0 argument.");
  }

  return facebook::jsi::Value(static_cast<double>(randombytes_random()));
}

facebook::jsi::Value RandombytesUniform(facebook::jsi::Runtime &runtime,
                                        const facebook::jsi::Value &,
                                        const facebook::jsi::Value *arguments,
                                        size_t count) {
  if (count != 1) {
    throw facebook::jsi::JSError(
        runtime, "Incorrect number of arguments. Expected 1 argument.");
  }

  const double upper_bound = arguments[0].asNumber();

  return facebook::jsi::Value(
      static_cast<double>(randombytes_uniform(upper_bound)));
}

} // namespace sodiuma
} // namespace s77rt
