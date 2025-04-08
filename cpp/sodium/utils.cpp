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

facebook::jsi::Value SodiumHex2bin(facebook::jsi::Runtime &runtime,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *arguments,
                                   size_t) {
  uint8_t *const bin =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double bin_max_len = arguments[1].getNumber();

  const char *hex;
  auto copy_data_ptr_to_hex = [&hex](bool ascii, const void *data, size_t) {
    assert(ascii);
    hex = static_cast<const char *>(data);
  };
  arguments[2].getString(runtime).getStringData(runtime, copy_data_ptr_to_hex);
  const double hex_len = arguments[3].getNumber();

  const char *ignore;
  if (arguments[4].isNull()) {
    ignore = NULL;
  } else {
    auto copy_data_ptr_to_ignore = [&ignore](bool ascii, const void *data,
                                             size_t) {
      assert(ascii);
      ignore = static_cast<const char *>(data);
    };
    arguments[4].getString(runtime).getStringData(runtime,
                                                  copy_data_ptr_to_ignore);
  }

  uint8_t *const bin_len =
      arguments[5].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *const hex_end =
      arguments[6].isNull()
          ? NULL
          : arguments[6].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);

  return facebook::jsi::Value(
      sodium_hex2bin(bin, bin_max_len, hex, hex_len, ignore,
                     reinterpret_cast<size_t *const>(bin_len),
                     reinterpret_cast<const char **const>(hex_end)));
}

facebook::jsi::Value
SodiumBase64EncodedLen(facebook::jsi::Runtime &, const facebook::jsi::Value &,
                       const facebook::jsi::Value *arguments, size_t) {
  const double bin_len = arguments[0].getNumber();
  const double variant = arguments[1].getNumber();

  return facebook::jsi::Value(
      static_cast<double>(sodium_base64_encoded_len(bin_len, variant)));
}

facebook::jsi::Value SodiumBin2base64(facebook::jsi::Runtime &runtime,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *arguments,
                                      size_t) {
  uint8_t *const b64 =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double b64_max_len = arguments[1].getNumber();
  uint8_t *const bin =
      arguments[2].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double bin_len = arguments[3].getNumber();
  const double variant = arguments[4].getNumber();

  return facebook::jsi::Value(facebook::jsi::String::createFromAscii(
      runtime, sodium_bin2base64(reinterpret_cast<char *const>(b64),
                                 b64_max_len, bin, bin_len, variant)));
}

facebook::jsi::Value SodiumBase642bin(facebook::jsi::Runtime &runtime,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *arguments,
                                      size_t) {
  uint8_t *const bin =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double bin_max_len = arguments[1].getNumber();

  const char *b64;
  auto copy_data_ptr_to_b64 = [&b64](bool ascii, const void *data, size_t) {
    assert(ascii);
    b64 = static_cast<const char *>(data);
  };
  arguments[2].getString(runtime).getStringData(runtime, copy_data_ptr_to_b64);
  const double b64_len = arguments[3].getNumber();

  const char *ignore;
  if (arguments[4].isNull()) {
    ignore = NULL;
  } else {
    auto copy_data_ptr_to_ignore = [&ignore](bool ascii, const void *data,
                                             size_t) {
      assert(ascii);
      ignore = static_cast<const char *>(data);
    };
    arguments[4].getString(runtime).getStringData(runtime,
                                                  copy_data_ptr_to_ignore);
  }

  uint8_t *const bin_len =
      arguments[5].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *const b64_end =
      arguments[6].isNull()
          ? NULL
          : arguments[6].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);
  const double variant = arguments[7].getNumber();

  return facebook::jsi::Value(sodium_base642bin(
      bin, bin_max_len, b64, b64_len, ignore,
      reinterpret_cast<size_t *const>(bin_len),
      reinterpret_cast<const char **const>(b64_end), variant));
}

facebook::jsi::Value SodiumIncrement(facebook::jsi::Runtime &runtime,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *arguments,
                                     size_t) {
  uint8_t *n =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double n_len = arguments[1].getNumber();

  sodium_increment(n, n_len);

  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumAdd(facebook::jsi::Runtime &runtime,
                               const facebook::jsi::Value &,
                               const facebook::jsi::Value *arguments, size_t) {
  uint8_t *a =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *b =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double len = arguments[2].getNumber();

  sodium_add(a, b, len);

  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumSub(facebook::jsi::Runtime &runtime,
                               const facebook::jsi::Value &,
                               const facebook::jsi::Value *arguments, size_t) {
  uint8_t *a =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *b =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double len = arguments[2].getNumber();

  sodium_sub(a, b, len);

  return facebook::jsi::Value::undefined();
}

facebook::jsi::Value SodiumCompare(facebook::jsi::Runtime &runtime,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *arguments,
                                   size_t) {
  uint8_t *const b1_ =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *const b2_ =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double len = arguments[2].getNumber();

  return facebook::jsi::Value(sodium_compare(b1_, b2_, len));
}

facebook::jsi::Value SodiumIsZero(facebook::jsi::Runtime &runtime,
                                  const facebook::jsi::Value &,
                                  const facebook::jsi::Value *arguments,
                                  size_t) {
  uint8_t *n =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double n_len = arguments[1].getNumber();

  return facebook::jsi::Value(sodium_is_zero(n, n_len));
}

facebook::jsi::Value SodiumStackzero(facebook::jsi::Runtime &,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *arguments,
                                     size_t) {
  const double len = arguments[0].getNumber();

  sodium_stackzero(len);

  return facebook::jsi::Value::undefined();
}

} // namespace sodiuma
} // namespace s77rt
