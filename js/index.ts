import "./NativeRTNSodium";

if (!globalThis.__s77rt__sodiuma) {
	console.error("[@s77rt/react-native-sodium] sodiuma object not found");
}

type Sodium = {
	randombytes_BYTES_MAX: number;
	randombytes_SEEDBYTES: number;

	crypto_generichash_BYTES_MIN: number;
	crypto_generichash_BYTES_MAX: number;
	crypto_generichash_BYTES: number;
	crypto_generichash_KEYBYTES_MIN: number;
	crypto_generichash_KEYBYTES_MAX: number;
	crypto_generichash_KEYBYTES: number;
	crypto_generichash_PRIMITIVE: string;

	crypto_shorthash_BYTES: number;
	crypto_shorthash_KEYBYTES: number;
	crypto_shorthash_PRIMITIVE: string;

	randombytes_random: () => number;
	randombytes_uniform: (upperBound: number) => number;
	randombytes_buf: (buf: ArrayBuffer, size: number) => void;
	randombytes_buf_deterministic: (
		buf: ArrayBuffer,
		size: number,
		seed: ArrayBuffer
	) => void;
	randombytes_close: () => number;
	randombytes_stir: () => void;

	crypto_generichash: (
		output: ArrayBuffer,
		outputLen: number,
		input: ArrayBuffer,
		inputLen: number,
		key: ArrayBuffer,
		keyLen: number
	) => number;
	crypto_generichash_init: (
		state: Record<string, never>,
		key: ArrayBuffer,
		keyLen: number,
		outputLen: number
	) => number;
	crypto_generichash_update: (
		state: Record<string, never>,
		input: ArrayBuffer,
		inputLen: number
	) => number;
	crypto_generichash_final: (
		state: Record<string, never>,
		output: ArrayBuffer,
		outputLen: number
	) => number;
	crypto_generichash_keygen: (k: ArrayBuffer) => void;

	crypto_shorthash: (
		output: ArrayBuffer,
		input: ArrayBuffer,
		inputLen: number,
		k: ArrayBuffer
	) => number;
	crypto_shorthash_keygen: (k: ArrayBuffer) => void;
};

// TODO(s77rt): Copy & cache host object properties

const sodium: Sodium = globalThis.__s77rt__sodiuma;

export default sodium;
