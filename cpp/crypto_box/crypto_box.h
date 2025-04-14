#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoBoxKeypair(facebook::jsi::Runtime &,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoBoxEasy(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoBoxOpenEasy(facebook::jsi::Runtime &,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoBoxSeal(facebook::jsi::Runtime &,
                                   const facebook::jsi::Value &,
                                   const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoBoxSealOpen(facebook::jsi::Runtime &,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *, size_t);

} // namespace sodiuma
} // namespace s77rt
