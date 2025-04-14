#pragma once

#include "crypto_box/crypto_box.h"
#include "crypto_generichash/crypto_generichash.h"
#include "crypto_shorthash/crypto_shorthash.h"
#include "randombytes/randombytes.h"
#include "sodium/core.h"
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
  static inline const std::map<
      std::string, std::variant<unsigned long long, int, std::string>>
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

          {"crypto_box_seedbytes", crypto_box_SEEDBYTES},
          {"crypto_box_publickeybytes", crypto_box_PUBLICKEYBYTES},
          {"crypto_box_secretkeybytes", crypto_box_SECRETKEYBYTES},
          {"crypto_box_noncebytes", crypto_box_NONCEBYTES},
          {"crypto_box_macbytes", crypto_box_MACBYTES},
          {"crypto_box_messagebytes_max", crypto_box_MESSAGEBYTES_MAX},
          {"crypto_box_primitive", crypto_box_PRIMITIVE},
          {"crypto_box_beforenmbytes", crypto_box_BEFORENMBYTES},
          {"crypto_box_sealbytes", crypto_box_SEALBYTES},
          {"crypto_box_zerobytes", crypto_box_ZEROBYTES},
          {"crypto_box_boxzerobytes", crypto_box_BOXZEROBYTES},

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
          {"sodium_init", {SodiumInit, 0}},

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

          {"sodium_pad", {SodiumPad, 5}},
          {"sodium_unpad", {SodiumUnpad, 4}},

          {"crypto_box_keypair", {CryptoBoxKeypair, 2}},
          {"crypto_box_easy", {CryptoBoxEasy, 6}},
          {"crypto_box_open_easy", {CryptoBoxOpenEasy, 6}},
          {"crypto_box_seal", {CryptoBoxSeal, 4}},
          {"crypto_box_seal_open", {CryptoBoxSealOpen, 5}},

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

// Inject sodiuma object into js globals
void Install(facebook::jsi::Runtime &runtime);

} // namespace sodiuma
} // namespace s77rt
