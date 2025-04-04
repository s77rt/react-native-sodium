#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value RandombytesRandom(facebook::jsi::Runtime &,
                                       const facebook::jsi::Value &,
                                       const facebook::jsi::Value *, size_t);

facebook::jsi::Value RandombytesUniform(facebook::jsi::Runtime &,
                                        const facebook::jsi::Value &,
                                        const facebook::jsi::Value *, size_t);

facebook::jsi::Value RandombytesBuf(facebook::jsi::Runtime &,
                                    const facebook::jsi::Value &,
                                    const facebook::jsi::Value *, size_t);

facebook::jsi::Value RandombytesBufDeterministic(facebook::jsi::Runtime &,
                                                 const facebook::jsi::Value &,
                                                 const facebook::jsi::Value *,
                                                 size_t);

facebook::jsi::Value RandombytesClose(facebook::jsi::Runtime &,
                                      const facebook::jsi::Value &,
                                      const facebook::jsi::Value *, size_t);

facebook::jsi::Value RandombytesStir(facebook::jsi::Runtime &,
                                     const facebook::jsi::Value &,
                                     const facebook::jsi::Value *, size_t);
} // namespace sodiuma
} // namespace s77rt
