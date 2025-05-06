#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoSignKeypair(facebook::jsi::Runtime &,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoSignSeedKeypair(facebook::jsi::Runtime &,
                                           const facebook::jsi::Value &,
                                           const facebook::jsi::Value *,
                                           size_t);

facebook::jsi::Value CryptoSign(facebook::jsi::Runtime &,
                                const facebook::jsi::Value &,
                                const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoSignOpen(facebook::jsi::Runtime &,
                                    const facebook::jsi::Value &,
                                    const facebook::jsi::Value *, size_t);

} // namespace sodiuma
} // namespace s77rt
