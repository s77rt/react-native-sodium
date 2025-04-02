#include "sodiuma_ho.h"

namespace s77rt {
namespace sodiuma {

SodiumaHostObject::~SodiumaHostObject() {}

facebook::jsi::Value
SodiumaHostObject::get(facebook::jsi::Runtime &,
                       const facebook::jsi::PropNameID &name) {
  return facebook::jsi::Value(5);
}

void SodiumaHostObject::set(facebook::jsi::Runtime &,
                            const facebook::jsi::PropNameID &name,
                            const facebook::jsi::Value &value) {
  return;
}

std::vector<facebook::jsi::PropNameID>
SodiumaHostObject::getPropertyNames(facebook::jsi::Runtime &rt) {
  std::vector<facebook::jsi::PropNameID> result;
  return result;
}

} // namespace sodiuma
} // namespace s77rt
