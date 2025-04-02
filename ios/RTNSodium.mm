#import "RTNSodium.h"
#import "sodiuma.h"

@implementation RTNSodium

RCT_EXPORT_MODULE()

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params {
  return std::make_shared<facebook::react::NativeRTNSodiumSpecJSI>(params);
}

- (void)
    installJSIBindingsWithRuntime:(facebook::jsi::Runtime &)runtime
                      callInvoker:
                          (const std::shared_ptr<facebook::react::CallInvoker>
                               &)callInvoker {
  s77rt::sodiuma::Install(runtime);
}

@end
