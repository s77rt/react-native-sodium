package com.s77rt.rtnsodium

import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.turbomodule.core.interfaces.BindingsInstallerHolder
import com.facebook.react.turbomodule.core.interfaces.TurboModuleWithJSIBindings

class RTNSodiumModule(
    reactContext: ReactApplicationContext,
) : NativeRTNSodiumSpec(reactContext),
    TurboModuleWithJSIBindings {
    override fun getName() = NAME

    external override fun getBindingsInstaller(): BindingsInstallerHolder

    companion object {
        const val NAME = "RTNSodium"
    }
}
