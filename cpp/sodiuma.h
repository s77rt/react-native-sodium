#pragma once

#include "crypto_generichash/crypto_generichash.h"
#include "crypto_shorthash/crypto_shorthash.h"
#include "randombytes/randombytes.h"
#include "sodium/utils.h"

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
  static inline const std::map<std::string,
                               std::variant<size_t, int, std::string>>
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

          {"sodium_base64_VARIANT_ORIGINAL", sodium_base64_VARIANT_ORIGINAL},
          {"sodium_base64_VARIANT_ORIGINAL_NO_PADDING",
           sodium_base64_VARIANT_ORIGINAL_NO_PADDING},
          {"sodium_base64_VARIANT_URLSAFE", sodium_base64_VARIANT_URLSAFE},
          {"sodium_base64_VARIANT_URLSAFE_NO_PADDING",
           sodium_base64_VARIANT_URLSAFE_NO_PADDING},
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
          {"crypto_shorthash_keygen", {CryptoShorthashKeygen, 1}},

          {"sodium_memcmp", {SodiumMemcmp, 3}},
          {"sodium_bin2hex", {SodiumBin2hex, 4}},
          {"sodium_hex2bin", {SodiumHex2bin, 7}},
          {"sodium_base64_encoded_len", {SodiumBase64EncodedLen, 2}},
          {"sodium_bin2base64", {SodiumBin2base64, 5}},
          {"sodium_base642bin", {SodiumBase642bin, 8}},
          {"sodium_increment", {SodiumIncrement, 2}},
          {"sodium_add", {SodiumAdd, 3}},
          {"sodium_sub", {SodiumSub, 3}},
          {"sodium_compare", {SodiumCompare, 3}},
          {"sodium_is_zero", {SodiumIsZero, 2}},
          {"sodium_stackzero", {SodiumStackzero, 1}}};
};

// Initialize libsodium and inject sodiuma object into js globals
void Install(facebook::jsi::Runtime &runtime);

} // namespace sodiuma
} // namespace s77rt
