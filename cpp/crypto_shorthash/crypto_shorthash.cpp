#include "crypto_generichash.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoShorthash(facebook::jsi::Runtime &runtime,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *arguments,
                                     size_t) {
  uint8_t *out =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *in =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double in_len = arguments[2].getNumber();
  uint8_t *k =
      arguments[3].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_shorthash(out, in, in_len, k));
}

facebook::jsi::Value
CryptoShorthashKeygen(facebook::jsi::Runtime &runtime,
                      const facebook::jsi::Value &,
                      const facebook::jsi::Value *arguments, size_t) {
  unsigned char k[crypto_shorthash_KEYBYTES];

  crypto_shorthash_keygen(k);

  memcpy(arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime),
         k, sizeof(k));

  return facebook::jsi::Value::undefined();
}

} // namespace sodiuma
} // namespace s77rt
