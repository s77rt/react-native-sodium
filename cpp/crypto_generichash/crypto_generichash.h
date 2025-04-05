#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value CryptoGenerichash(facebook::jsi::Runtime &,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *, size_t);

facebook::jsi::Value CryptoGenerichashInit(facebook::jsi::Runtime &,
                                           const facebook::jsi::Value &,
                                           const facebook::jsi::Value *,
                                           size_t);

facebook::jsi::Value CryptoGenerichashUpdate(facebook::jsi::Runtime &,
                                             const facebook::jsi::Value &,
                                             const facebook::jsi::Value *,
                                             size_t);

facebook::jsi::Value CryptoGenerichashFinal(facebook::jsi::Runtime &,
                                            const facebook::jsi::Value &,
                                            const facebook::jsi::Value *,
                                            size_t);

} // namespace sodiuma
} // namespace s77rt
