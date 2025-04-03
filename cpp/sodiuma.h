#pragma once

#include <jsi/jsi.h>

namespace s77rt {
namespace sodiuma {

// Sodiuma Host Object
class Sodiuma : public facebook::jsi::HostObject {
public:
  facebook::jsi::Value get(facebook::jsi::Runtime &,
                           const facebook::jsi::PropNameID &name);
  std::vector<facebook::jsi::PropNameID>
  getPropertyNames(facebook::jsi::Runtime &rt);
};

// Initialize libsodium and inject sodiuma object into js globals
void Install(facebook::jsi::Runtime &runtime);

} // namespace sodiuma
} // namespace s77rt
