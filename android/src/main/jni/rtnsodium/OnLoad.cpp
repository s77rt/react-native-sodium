#include "JRTNSodiumModule.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
  return facebook::jni::initialize(
      vm, [] { s77rt::sodiuma::jni::JRTNSodiumModule::registerNatives(); });
}
