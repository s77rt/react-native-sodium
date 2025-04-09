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
		key: ArrayBuffer | null,
		keyLen: number
	) => number;
	crypto_generichash_init: (
		state: Record<string, never>,
		key: ArrayBuffer | null,
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

	sodium_pad: (
		paddedBufLenP: ArrayBuffer,
		buf: ArrayBuffer,
		unpaddedBufLen: number,
		blockSize: number,
		maxBufLen: number
	) => number;
	sodium_unpad: (
		unpaddedBufLenP: ArrayBuffer,
		buf: ArrayBuffer,
		paddedBufLen: number,
		blockSize: number
	) => number;

	sodium_memcmp: (b1_: ArrayBuffer, b2_: ArrayBuffer, len: number) => number;
	sodium_bin2hex: (
		hex: ArrayBuffer,
		hexMaxLen: number,
		bin: ArrayBuffer,
		binLen: number
	) => string;
	sodium_hex2bin: (
		bin: ArrayBuffer,
		binMaxLen: number,
		hex: string,
		hexLen: number,
		ignore: string | null,
		binLen: ArrayBuffer,
		hexEnd: ArrayBuffer | null
	) => number;
	sodium_base64_encoded_len: (binLen: number, variant: number) => number;
	sodium_bin2base64: (
		b64: ArrayBuffer,
		b64MaxLen: number,
		bin: ArrayBuffer,
		binLen: number,
		variant: number
	) => string;
	sodium_base642bin: (
		bin: ArrayBuffer,
		binMaxLen: number,
		b64: string,
		b64Len: number,
		ignore: string | null,
		binLen: ArrayBuffer,
		b64End: ArrayBuffer | null,
		variant: number
	) => number;
	sodium_increment: (n: ArrayBuffer, nLen: number) => void;
	sodium_add: (a: ArrayBuffer, b: ArrayBuffer, len: number) => void;
	sodium_sub: (a: ArrayBuffer, b: ArrayBuffer, len: number) => void;
	sodium_compare: (b1_: ArrayBuffer, b2_: ArrayBuffer, len: number) => number;
	sodium_is_zero: (n: ArrayBuffer, nLen: number) => number;
	sodium_stackzero: (len: number) => void;
};

// TODO(s77rt): Copy & cache host object properties

const sodium: Sodium = globalThis.__s77rt__sodiuma;

export default sodium;
