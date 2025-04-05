import "./NativeRTNSodium";
export * from "./helpers";

if (!globalThis.__s77rt__sodiuma) {
	console.error("[@s77rt/react-native-sodium] sodiuma object not found");
}

// TODO(s77rt): Copy & cache host object properties

export default globalThis.__s77rt__sodiuma;
