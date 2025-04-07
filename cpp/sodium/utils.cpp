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

  size_t bin_len;

  uint8_t *const hex_end =
      arguments[6].isNull()
          ? NULL
          : arguments[6].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);

  int ret = sodium_hex2bin(bin, bin_max_len, hex, hex_len, ignore, &bin_len,
                           reinterpret_cast<const char **const>(hex_end));

  memcpy(arguments[5].getObject(runtime).getArrayBuffer(runtime).data(runtime),
         &bin_len, sizeof(bin_len));

  return facebook::jsi::Value(ret);
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
