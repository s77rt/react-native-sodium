#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value SodiumMemcmp(facebook::jsi::Runtime &,
                                  const facebook::jsi::Value &,
                                  const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumBin2hex(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumHex2bin(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumBin2base64(facebook::jsi::Runtime &,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumBase642bin(facebook::jsi::Runtime &,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumIncrement(facebook::jsi::Runtime &,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumAdd(facebook::jsi::Runtime &,
                               const facebook::jsi::Value &,
                               const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumSub(facebook::jsi::Runtime &,
                               const facebook::jsi::Value &,
                               const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumCompare(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumIsZero(facebook::jsi::Runtime &,
                                  const facebook::jsi::Value &,
                                  const facebook::jsi::Value *, size_t);

facebook::jsi::Value SodiumStackzero(facebook::jsi::Runtime &,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *, size_t);

} // namespace sodiuma
} // namespace s77rt
