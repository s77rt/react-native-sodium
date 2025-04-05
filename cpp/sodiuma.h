#pragma once

#include "crypto_generichash/crypto_generichash.h"
#include "randombytes/randombytes.h"

#include <jsi/jsi.h>
#include <map>

namespace s77rt {
namespace sodiuma {

// Sodiuma Host Object
class Sodiuma : public facebook::jsi::HostObject {
public:
  facebook::jsi::Value get(facebook::jsi::Runtime &,
                           const facebook::jsi::PropNameID &name) override;
  std::vector<facebook::jsi::PropNameID>
  getPropertyNames(facebook::jsi::Runtime &rt) override;

private:
  static inline const std::map<
      std::string, std::pair<facebook::jsi::HostFunctionType, unsigned int>>
      property_functions_{
          {"randombytes_random", {RandombytesRandom, 0}},
          {"randombytes_uniform", {RandombytesUniform, 1}},
          {"randombytes_buf", {RandombytesBuf, 2}},
          {"randombytes_buf_deterministic", {RandombytesBufDeterministic, 3}},
          {"randombytes_close", {RandombytesClose, 0}},
          {"randombytes_stir", {RandombytesStir, 0}},
          {"crypto_generichash", {CryptoGenerichash, 6}},
          {"crypto_generichash_init", {CryptoGenerichashInit, 4}},
          {"crypto_generichash_update", {CryptoGenerichashUpdate, 3}},
          {"crypto_generichash_final", {CryptoGenerichashFinal, 3}},
          {"crypto_generichash_keygen", {CryptoGenerichashKeygen, 1}}};
};

// Initialize libsodium and inject sodiuma object into js globals
void Install(facebook::jsi::Runtime &runtime);

} // namespace sodiuma
} // namespace s77rt
