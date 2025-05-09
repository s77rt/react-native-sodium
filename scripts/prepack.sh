#!/bin/bash

set -e

rm -rf vendor/libsodium
mkdir -p vendor/libsodium

rm -rf libsodium
git submodule update

cd libsodium
ANDROID_NDK_HOME="$ANDROID_HOME/ndk/27.1.12297006" NDK_PLATFORM="android-24" ./dist-build/android-aar.sh
mv libsodium-*.aar ../vendor/libsodium/
IOS_VERSION_MIN="15.1" ./dist-build/apple-xcframework.sh
mv libsodium-apple/Clibsodium.xcframework ../vendor/libsodium/
