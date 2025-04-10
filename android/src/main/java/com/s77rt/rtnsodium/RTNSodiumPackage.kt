package com.s77rt.rtnsodium

import com.facebook.react.BaseReactPackage
import com.facebook.react.bridge.NativeModule
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.module.model.ReactModuleInfo
import com.facebook.react.module.model.ReactModuleInfoProvider

class RTNSodiumPackage : BaseReactPackage() {
    init {
        System.loadLibrary("rtnsodium-jni")
    }

    override fun getModule(
        name: String,
        reactContext: ReactApplicationContext,
    ): NativeModule? =
        if (name == RTNSodiumModule.NAME) {
            RTNSodiumModule(reactContext)
        } else {
            null
        }

    override fun getReactModuleInfoProvider() =
        ReactModuleInfoProvider {
            mapOf(
                RTNSodiumModule.NAME to
                    ReactModuleInfo(
                        RTNSodiumModule.NAME,
                        RTNSodiumModule.NAME,
                        false, // canOverrideExistingModule
                        false, // needsEagerInit
                        false, // isCxxModule
                        true, // isTurboModule
                    ),
            )
        }
}
