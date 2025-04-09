#include "core.h"

#include <sodium.h>

namespace s77rt {
namespace sodiuma {

facebook::jsi::Value SodiumInit(facebook::jsi::Runtime &,
                                const facebook::jsi::Value &,
                                const facebook::jsi::Value *, size_t) {
  return facebook::jsi::Value(sodium_init());
}

} // namespace sodiuma
} // namespace s77rt
