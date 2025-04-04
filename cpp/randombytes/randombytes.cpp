#include "randombytes.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value RandombytesRandom(facebook::jsi::Runtime &,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *, size_t) {

  return facebook::jsi::Value(static_cast<double>(randombytes_random()));
}

facebook::jsi::Value RandombytesUniform(facebook::jsi::Runtime &,
                                        const facebook::jsi::Value &,
                                        const facebook::jsi::Value *arguments,
                                        size_t) {

  const double upper_bound = arguments[0].getNumber();

  return facebook::jsi::Value(
      static_cast<double>(randombytes_uniform(upper_bound)));
}

facebook::jsi::Value RandombytesBuf(facebook::jsi::Runtime &runtime,
                                    const facebook::jsi::Value &,
                                    const facebook::jsi::Value *arguments,
                                    size_t) {

  uint8_t *const buf =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double size = arguments[1].getNumber();

  randombytes_buf(buf, size);

  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value
RandombytesBufDeterministic(facebook::jsi::Runtime &runtime,
                            const facebook::jsi::Value &,
                            const facebook::jsi::Value *arguments, size_t) {

  uint8_t *const buf =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double size = arguments[1].getNumber();

  unsigned char seed[randombytes_SEEDBYTES] = {0};
  auto copy_string_to_seed = [&seed](bool, const void *data, size_t num) {
    memcpy(&seed[0], data, num);
  };
  arguments[2].getString(runtime).getStringData(runtime, copy_string_to_seed);

  randombytes_buf_deterministic(buf, size, seed);

  return facebook::jsi::Value::undefined();
}

} // namespace sodiuma
} // namespace s77rt
