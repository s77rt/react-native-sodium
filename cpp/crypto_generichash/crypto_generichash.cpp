#include "crypto_generichash.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoGenerichash(facebook::jsi::Runtime &runtime,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *arguments,
                                       size_t) {
  uint8_t *out =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double out_len = arguments[1].getNumber();
  uint8_t *in =
      arguments[2].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double in_len = arguments[3].getNumber();
  uint8_t *key =
      arguments[4].isNull()
          ? NULL
          : arguments[4].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);
  const double key_len = arguments[5].getNumber();

  return facebook::jsi::Value(
      crypto_generichash(out, out_len, in, in_len, key, key_len));
}

} // namespace sodiuma
} // namespace s77rt
