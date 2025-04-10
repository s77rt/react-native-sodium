cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

project(rtnsodium-jni)

find_package(ReactAndroid REQUIRED CONFIG)
find_package(fbjni REQUIRED CONFIG)

add_compile_options(
        -fexceptions
        -frtti
        -std=c++20)

file(GLOB JNI_CPP_FILES CONFIGURE_DEPENDS rtnsodium/*.cpp)
file(GLOB_RECURSE COMMON_CPP_FILES CONFIGURE_DEPENDS ../../../../cpp/*.cpp)

add_library(rtnsodium-jni SHARED ${JNI_CPP_FILES} ${COMMON_CPP_FILES})

target_include_directories(rtnsodium-jni PRIVATE ../../../../cpp)

target_include_directories(rtnsodium-jni PRIVATE
    "${REACT_NATIVE_DIR}/ReactCommon"
    "${REACT_NATIVE_DIR}/ReactCommon/react/nativemodule/core"
    "${REACT_NATIVE_DIR}/ReactCommon/callinvoker"
    "${REACT_NATIVE_DIR}/ReactAndroid/src/main/jni/react/turbomodule")

target_link_libraries(rtnsodium-jni
        fbjni::fbjni
        ReactAndroid::jsi
        ReactAndroid::reactnative)
