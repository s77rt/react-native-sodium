#include "JRTNSodiumModule.h"

#include <jsi/jsi.h>

#include "sodiuma.h"

namespace s77rt {
namespace sodiuma {
namespace jni {

void JRTNSodiumModule::registerNatives() {
  javaClassLocal()->registerNatives({
      makeNativeMethod("getBindingsInstaller",
                       JRTNSodiumModule::getBindingsInstaller),
  });
}

facebook::jni::local_ref<facebook::react::BindingsInstallerHolder::javaobject>
JRTNSodiumModule::getBindingsInstaller(
    facebook::jni::alias_ref<JRTNSodiumModule>) {
  return facebook::jni::make_local(
      facebook::react::BindingsInstallerHolder::newObjectCxxArgs(
          [](facebook::jsi::Runtime &runtime,
             const std::shared_ptr<facebook::react::CallInvoker> &) {
            s77rt::sodiuma::Install(runtime);
          }));
}

} // namespace jni
} // namespace sodiuma
} // namespace s77rt
