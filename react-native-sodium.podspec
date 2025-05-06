require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name            = "react-native-sodium"
  s.version         = package["version"]
  s.summary         = package["description"]
  s.description     = package["description"]
  s.homepage        = package["homepage"]
  s.license         = package["license"]
  s.platforms       = { :ios => min_ios_version_supported }
  s.author          = package["author"]
  s.source          = { :git => "", :tag => "#{s.version}" }

  s.source_files    = ["ios/**/*.{h,m,mm,swift}"]

  s.prepare_command = "cd libsodium && IOS_VERSION_MIN=#{min_ios_version_supported} ./dist-build/apple-xcframework.sh"

  s.subspec 'libsodium' do |sp|
    sp.vendored_frameworks = "libsodium/libsodium-apple/Clibsodium.xcframework"
  end

  s.subspec 'sodiuma' do |sp|
    sp.source_files = ["cpp/**/*.{h,cpp}"]
    sp.dependency 'react-native-sodium/libsodium'
  end

  s.pod_target_xcconfig = {
    "CLANG_CXX_LANGUAGE_STANDARD" => "c++20"
  }

  install_modules_dependencies(s)
end
