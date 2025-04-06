#pragma once

#include "crypto_generichash/crypto_generichash.h"
#include "crypto_shorthash/crypto_shorthash.h"
#include "randombytes/randombytes.h"

#include <jsi/jsi.h>
#include <map>
#include <sodium.h>

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
  static inline const std::map<std::string, std::variant<size_t, std::string>>
      property_constants_{
          {"randombytes_BYTES_MAX", randombytes_BYTES_MAX},
          {"randombytes_SEEDBYTES", randombytes_SEEDBYTES},

          {"crypto_generichash_BYTES_MIN", crypto_generichash_BYTES_MIN},
          {"crypto_generichash_BYTES_MAX", crypto_generichash_BYTES_MAX},
          {"crypto_generichash_BYTES", crypto_generichash_BYTES},
          {"crypto_generichash_KEYBYTES_MIN", crypto_generichash_KEYBYTES_MIN},
          {"crypto_generichash_KEYBYTES_MAX", crypto_generichash_KEYBYTES_MAX},
          {"crypto_generichash_KEYBYTES", crypto_generichash_KEYBYTES},
          {"crypto_generichash_PRIMITIVE", crypto_generichash_PRIMITIVE},

          {"crypto_shorthash_BYTES", crypto_shorthash_BYTES},
          {"crypto_shorthash_KEYBYTES", crypto_shorthash_KEYBYTES},
          {"crypto_shorthash_PRIMITIVE", crypto_shorthash_PRIMITIVE},
      };

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
          {"crypto_generichash_keygen", {CryptoGenerichashKeygen, 1}},

          {"crypto_shorthash", {CryptoShorthash, 4}},
          {"crypto_shorthash_keygen", {CryptoShorthashKeygen, 1}}};
};

// Initialize libsodium and inject sodiuma object into js globals
void Install(facebook::jsi::Runtime &runtime);

} // namespace sodiuma
} // namespace s77rt
