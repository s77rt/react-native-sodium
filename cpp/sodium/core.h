#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value SodiumInit(facebook::jsi::Runtime &,
                                const facebook::jsi::Value &,
                                const facebook::jsi::Value *, size_t);

} // namespace sodiuma
} // namespace s77rt
