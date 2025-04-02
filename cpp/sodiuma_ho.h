#pragma once

#include <jsi/jsi.h>
#include <vector>

namespace s77rt {
namespace sodiuma {

class SodiumaHostObject : public facebook::jsi::HostObject {

public:
  ~SodiumaHostObject();
  facebook::jsi::Value get(facebook::jsi::Runtime &,
                           const facebook::jsi::PropNameID &name);
  void set(facebook::jsi::Runtime &, const facebook::jsi::PropNameID &name,
           const facebook::jsi::Value &value);
  std::vector<facebook::jsi::PropNameID>
  getPropertyNames(facebook::jsi::Runtime &rt);
};

} // namespace sodiuma
} // namespace s77rt
