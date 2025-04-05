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

struct CryptoGenerichashState : public facebook::jsi::NativeState {
  crypto_generichash_state state;
};

facebook::jsi::Value
CryptoGenerichashInit(facebook::jsi::Runtime &runtime,
                      const facebook::jsi::Value &,
                      const facebook::jsi::Value *arguments, size_t) {
  facebook::jsi::Object state = arguments[0].getObject(runtime);
  state.setNativeState(runtime, std::make_shared<CryptoGenerichashState>());
  uint8_t *key =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double key_len = arguments[2].getNumber();
  const double out_len = arguments[3].getNumber();

  return facebook::jsi::Value(crypto_generichash_init(
      &(state.getNativeState<CryptoGenerichashState>(runtime)->state), key,
      key_len, out_len));
}

facebook::jsi::Value
CryptoGenerichashUpdate(facebook::jsi::Runtime &runtime,
                        const facebook::jsi::Value &,
                        const facebook::jsi::Value *arguments, size_t) {
  facebook::jsi::Object state = arguments[0].getObject(runtime);
  uint8_t *in =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double in_len = arguments[2].getNumber();

  return facebook::jsi::Value(crypto_generichash_update(
      &(state.getNativeState<CryptoGenerichashState>(runtime)->state), in,
      in_len));
}

facebook::jsi::Value
CryptoGenerichashFinal(facebook::jsi::Runtime &runtime,
                       const facebook::jsi::Value &,
                       const facebook::jsi::Value *arguments, size_t) {
  facebook::jsi::Object state = arguments[0].getObject(runtime);
  uint8_t *out =
      arguments[1].getObject(runtime).getArrayBuffer(runtime).data(runtime);
  const double out_len = arguments[2].getNumber();

  return facebook::jsi::Value(crypto_generichash_final(
      &(state.getNativeState<CryptoGenerichashState>(runtime)->state), out,
      out_len));
}

} // namespace sodiuma
} // namespace s77rt
