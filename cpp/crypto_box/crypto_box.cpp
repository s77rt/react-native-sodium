#include "crypto_box.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoBoxKeypair(facebook::jsi::Runtime &runtime,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *arguments,
                                      size_t) {
  uint8_t *pk =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sk =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_box_keypair(pk, sk));
}

facebook::jsi::Value CryptoBoxEasy(facebook::jsi::Runtime &runtime,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *arguments,
                                   size_t) {
  uint8_t *c =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *m =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double m_len = arguments[2].getNumber();
  uint8_t *n =
      arguments[3].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *pk =
      arguments[4].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sk =
      arguments[5].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_box_easy(c, m, m_len, n, pk, sk));
}

facebook::jsi::Value CryptoBoxOpenEasy(facebook::jsi::Runtime &runtime,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *arguments,
                                       size_t) {
  uint8_t *m =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *c =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double c_len = arguments[2].getNumber();
  uint8_t *n =
      arguments[3].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *pk =
      arguments[4].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sk =
      arguments[5].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_box_open_easy(m, c, c_len, n, pk, sk));
}

facebook::jsi::Value CryptoBoxSeal(facebook::jsi::Runtime &runtime,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *arguments,
                                   size_t) {
  uint8_t *c =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *m =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double m_len = arguments[2].getNumber();
  uint8_t *pk =
      arguments[3].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_box_seal(c, m, m_len, pk));
}

facebook::jsi::Value CryptoBoxSealOpen(facebook::jsi::Runtime &runtime,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *arguments,
                                       size_t) {
  uint8_t *m =
      arguments[0].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *c =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double c_len = arguments[2].getNumber();
  uint8_t *pk =
      arguments[3].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  uint8_t *sk =
      arguments[4].getObject(runtime).getArrayBuffer(runtime).data(runtime);

  return facebook::jsi::Value(crypto_box_seal_open(m, c, c_len, pk, sk));
}

} // namespace sodiuma
} // namespace s77rt
