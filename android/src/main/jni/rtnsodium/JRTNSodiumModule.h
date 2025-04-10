#pragma once

#include <ReactCommon/BindingsInstallerHolder.h>
#include <fbjni/fbjni.h>

namespace s77rt {
namespace sodiuma {
namespace jni {

class JRTNSodiumModule : public facebook::jni::JavaClass<JRTNSodiumModule> {
public:
  static constexpr const char *kJavaDescriptor =
      "Lcom/s77rt/rtnsodium/RTNSodiumModule;";

  JRTNSodiumModule() = default;

  static void registerNatives();

private:
  static facebook::jni::local_ref<
      facebook::react::BindingsInstallerHolder::javaobject>
  getBindingsInstaller(facebook::jni::alias_ref<JRTNSodiumModule> clazz);
};

} // namespace jni
} // namespace sodiuma
} // namespace s77rt
