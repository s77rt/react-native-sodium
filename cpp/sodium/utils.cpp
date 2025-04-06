#include "utils.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value SodiumMemcmp(facebook::jsi::Runtime &runtime,
                                  const facebook::jsi::Value &,
                                  const facebook::jsi::Value *arguments,
                                  size_t) {
  uint8_t *const b1_ =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *const b2_ =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double len = arguments[2].getNumber();

  return facebook::jsi::Value(sodium_memcmp(b1_, b2_, len));
}

facebook::jsi::Value SodiumBin2hex(facebook::jsi::Runtime &runtime,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *arguments,
                                   size_t) {
  uint8_t *const hex =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double hex_max_len = arguments[1].getNumber();
  uint8_t *const bin =
      arguments[2].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double bin_len = arguments[3].getNumber();

  return facebook::jsi::Value(facebook::jsi::String::createFromAscii(
      runtime, sodium_bin2hex(reinterpret_cast<char *const>(hex), hex_max_len,
                              bin, bin_len)));
}

facebook::jsi::Value SodiumHex2bin(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumBin2base64(facebook::jsi::Runtime &,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumBase642bin(facebook::jsi::Runtime &,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumIncrement(facebook::jsi::Runtime &,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumAdd(facebook::jsi::Runtime &,
                               const facebook::jsi::Value &,
                               const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumSub(facebook::jsi::Runtime &,
                               const facebook::jsi::Value &,
                               const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumCompare(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumIsZero(facebook::jsi::Runtime &,
                                  const facebook::jsi::Value &,
                                  const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumStackzero(facebook::jsi::Runtime &,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *, size_t) {
  // TODO(s77rt)
  return facebook::jsi::Value::undefined();
}

} // namespace sodiuma
} // namespace s77rt
