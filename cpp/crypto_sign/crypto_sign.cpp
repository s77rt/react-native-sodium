#include "crypto_sign.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoSignKeypair(facebook::jsi::Runtime &runtime,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *arguments,
                                       size_t) {
  uint8_t *pk =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sk =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_sign_keypair(pk, sk));
}

facebook::jsi::Value
CryptoSignSeedKeypair(facebook::jsi::Runtime &runtime,
                      const facebook::jsi::Value &,
                      const facebook::jsi::Value *arguments, size_t) {
  uint8_t *pk =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sk =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *seed =
      arguments[2].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_sign_seed_keypair(pk, sk, seed));
}

facebook::jsi::Value CryptoSign(facebook::jsi::Runtime &runtime,
                                const facebook::jsi::Value &,
                                const facebook::jsi::Value *arguments, size_t) {
  uint8_t *sm =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sm_len_p =
      arguments[1].isNull()
          ? NULL
          : arguments[1].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);
  uint8_t *m =
      arguments[2].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double m_len = arguments[3].getNumber();
  uint8_t *sk =
      arguments[4].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_sign(
      sm, reinterpret_cast<unsigned long long *>(sm_len_p), m, m_len, sk));
}

facebook::jsi::Value CryptoSignOpen(facebook::jsi::Runtime &runtime,
                                    const facebook::jsi::Value &,
                                    const facebook::jsi::Value *arguments,
                                    size_t) {
  uint8_t *m =
      arguments[0].isNull()
          ? NULL
          : arguments[0].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);
  uint8_t *m_len_p =
      arguments[1].isNull()
          ? NULL
          : arguments[1].getObject(runtime).getArrayBuffer(runtime).data(
                runtime);
  uint8_t *sm =
      arguments[2].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double sm_len = arguments[3].getNumber();
  uint8_t *pk =
      arguments[4].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_sign_open(
      m, reinterpret_cast<unsigned long long *>(m_len_p), sm, sm_len, pk));
}

} // namespace sodiuma
} // namespace s77rt
