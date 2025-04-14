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

	crypto_box_SEEDBYTES: number;
	crypto_box_PUBLICKEYBYTES: number;
	crypto_box_SECRETKEYBYTES: number;
	crypto_box_NONCEBYTES: number;
	crypto_box_MACBYTES: number;
	crypto_box_MESSAGEBYTES_MAX: number;
	crypto_box_PRIMITIVE: string;
	crypto_box_BEFORENMBYTES: number;
	crypto_box_SEALBYTES: number;
	crypto_box_ZEROBYTES: number;
	crypto_box_BOXZEROBYTES: number;

	crypto_sign_BYTES: number;
	crypto_sign_SEEDBYTES: number;
	crypto_sign_PUBLICKEYBYTES: number;
	crypto_sign_SECRETKEYBYTES: number;
	crypto_sign_MESSAGEBYTES_MAX: number;
	crypto_sign_PRIMITIVE: string;

	sodium_base64_VARIANT_ORIGINAL: number;
	sodium_base64_VARIANT_ORIGINAL_NO_PADDING: number;
	sodium_base64_VARIANT_URLSAFE: number;
	sodium_base64_VARIANT_URLSAFE_NO_PADDING: number;

	sodium_init: () => number;

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

	crypto_box_keypair: (pk: ArrayBuffer, sk: ArrayBuffer) => number;
	crypto_box_easy: (
		c: ArrayBuffer,
		m: ArrayBuffer,
		mLen: number,
		n: ArrayBuffer,
		pk: ArrayBuffer,
		sk: ArrayBuffer
	) => number;
	crypto_box_open_easy: (
		m: ArrayBuffer,
		c: ArrayBuffer,
		cLen: number,
		n: ArrayBuffer,
		pk: ArrayBuffer,
		sk: ArrayBuffer
	) => number;
	crypto_box_seal: (
		c: ArrayBuffer,
		m: ArrayBuffer,
		mLen: number,
		pk: ArrayBuffer
	) => number;
	crypto_box_seal_open: (
		m: ArrayBuffer,
		c: ArrayBuffer,
		cLen: number,
		pk: ArrayBuffer,
		sk: ArrayBuffer
	) => number;

	crypto_sign_keypair: (pk: ArrayBuffer, sk: ArrayBuffer) => number;
	crypto_sign: (
		sm: ArrayBuffer,
		smLenP: ArrayBuffer | null,
		m: ArrayBuffer,
		mLen: number,
		sk: ArrayBuffer
	) => number;
	crypto_sign_open: (
		m: ArrayBuffer | null,
		mLenP: ArrayBuffer | null,
		sm: ArrayBuffer,
		smLen: number,
		pk: ArrayBuffer
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

// Not exporting __s77rt__sodiuma directly so that we can cache the properties and avoid calling createFromHostFunction everytime.
//
// Spread syntax and Object.assign does not work on __s77rt__sodiuma if the js runtime is not ready.
const sodium: Sodium = {
	randombytes_BYTES_MAX: globalThis.__s77rt__sodiuma.randombytes_BYTES_MAX,
	randombytes_SEEDBYTES: globalThis.__s77rt__sodiuma.randombytes_SEEDBYTES,

	crypto_generichash_BYTES_MIN:
		globalThis.__s77rt__sodiuma.crypto_generichash_BYTES_MIN,
	crypto_generichash_BYTES_MAX:
		globalThis.__s77rt__sodiuma.crypto_generichash_BYTES_MAX,
	crypto_generichash_BYTES:
		globalThis.__s77rt__sodiuma.crypto_generichash_BYTES,
	crypto_generichash_KEYBYTES_MIN:
		globalThis.__s77rt__sodiuma.crypto_generichash_KEYBYTES_MIN,
	crypto_generichash_KEYBYTES_MAX:
		globalThis.__s77rt__sodiuma.crypto_generichash_KEYBYTES_MAX,
	crypto_generichash_KEYBYTES:
		globalThis.__s77rt__sodiuma.crypto_generichash_KEYBYTES,
	crypto_generichash_PRIMITIVE:
		globalThis.__s77rt__sodiuma.crypto_generichash_PRIMITIVE,

	crypto_shorthash_BYTES: globalThis.__s77rt__sodiuma.crypto_shorthash_BYTES,
	crypto_shorthash_KEYBYTES:
		globalThis.__s77rt__sodiuma.crypto_shorthash_KEYBYTES,
	crypto_shorthash_PRIMITIVE:
		globalThis.__s77rt__sodiuma.crypto_shorthash_PRIMITIVE,

	crypto_box_SEEDBYTES: globalThis.__s77rt__sodiuma.crypto_box_SEEDBYTES,
	crypto_box_PUBLICKEYBYTES:
		globalThis.__s77rt__sodiuma.crypto_box_PUBLICKEYBYTES,
	crypto_box_SECRETKEYBYTES:
		globalThis.__s77rt__sodiuma.crypto_box_SECRETKEYBYTES,
	crypto_box_NONCEBYTES: globalThis.__s77rt__sodiuma.crypto_box_NONCEBYTES,
	crypto_box_MACBYTES: globalThis.__s77rt__sodiuma.crypto_box_MACBYTES,
	crypto_box_MESSAGEBYTES_MAX:
		globalThis.__s77rt__sodiuma.crypto_box_MESSAGEBYTES_MAX,
	crypto_box_PRIMITIVE: globalThis.__s77rt__sodiuma.crypto_box_PRIMITIVE,
	crypto_box_BEFORENMBYTES:
		globalThis.__s77rt__sodiuma.crypto_box_BEFORENMBYTES,
	crypto_box_SEALBYTES: globalThis.__s77rt__sodiuma.crypto_box_SEALBYTES,
	crypto_box_ZEROBYTES: globalThis.__s77rt__sodiuma.crypto_box_ZEROBYTES,
	crypto_box_BOXZEROBYTES:
		globalThis.__s77rt__sodiuma.crypto_box_BOXZEROBYTES,

	crypto_sign_BYTES: globalThis.__s77rt__sodiuma.crypto_sign_BYTES,
	crypto_sign_SEEDBYTES: globalThis.__s77rt__sodiuma.crypto_sign_SEEDBYTES,
	crypto_sign_PUBLICKEYBYTES:
		globalThis.__s77rt__sodiuma.crypto_sign_PUBLICKEYBYTES,
	crypto_sign_SECRETKEYBYTES:
		globalThis.__s77rt__sodiuma.crypto_sign_SECRETKEYBYTES,
	crypto_sign_MESSAGEBYTES_MAX:
		globalThis.__s77rt__sodiuma.crypto_sign_MESSAGEBYTES_MAX,
	crypto_sign_PRIMITIVE: globalThis.__s77rt__sodiuma.crypto_sign_PRIMITIVE,

	sodium_base64_VARIANT_ORIGINAL:
		globalThis.__s77rt__sodiuma.sodium_base64_VARIANT_ORIGINAL,
	sodium_base64_VARIANT_ORIGINAL_NO_PADDING:
		globalThis.__s77rt__sodiuma.sodium_base64_VARIANT_ORIGINAL_NO_PADDING,
	sodium_base64_VARIANT_URLSAFE:
		globalThis.__s77rt__sodiuma.sodium_base64_VARIANT_URLSAFE,
	sodium_base64_VARIANT_URLSAFE_NO_PADDING:
		globalThis.__s77rt__sodiuma.sodium_base64_VARIANT_URLSAFE_NO_PADDING,

	sodium_init: globalThis.__s77rt__sodiuma.sodium_init,

	randombytes_random: globalThis.__s77rt__sodiuma.randombytes_random,
	randombytes_uniform: globalThis.__s77rt__sodiuma.randombytes_uniform,
	randombytes_buf: globalThis.__s77rt__sodiuma.randombytes_buf,
	randombytes_buf_deterministic:
		globalThis.__s77rt__sodiuma.randombytes_buf_deterministic,
	randombytes_close: globalThis.__s77rt__sodiuma.randombytes_close,
	randombytes_stir: globalThis.__s77rt__sodiuma.randombytes_stir,

	crypto_generichash: globalThis.__s77rt__sodiuma.crypto_generichash,
	crypto_generichash_init:
		globalThis.__s77rt__sodiuma.crypto_generichash_init,
	crypto_generichash_update:
		globalThis.__s77rt__sodiuma.crypto_generichash_update,
	crypto_generichash_final:
		globalThis.__s77rt__sodiuma.crypto_generichash_final,
	crypto_generichash_keygen:
		globalThis.__s77rt__sodiuma.crypto_generichash_keygen,

	crypto_shorthash: globalThis.__s77rt__sodiuma.crypto_shorthash,
	crypto_shorthash_keygen:
		globalThis.__s77rt__sodiuma.crypto_shorthash_keygen,

	sodium_pad: globalThis.__s77rt__sodiuma.sodium_pad,
	sodium_unpad: globalThis.__s77rt__sodiuma.sodium_unpad,

	crypto_box_keypair: globalThis.__s77rt__sodiuma.crypto_box_keypair,
	crypto_box_easy: globalThis.__s77rt__sodiuma.crypto_box_easy,
	crypto_box_open_easy: globalThis.__s77rt__sodiuma.crypto_box_open_easy,
	crypto_box_seal: globalThis.__s77rt__sodiuma.crypto_box_seal,
	crypto_box_seal_open: globalThis.__s77rt__sodiuma.crypto_box_seal_open,

	crypto_sign_keypair: globalThis.__s77rt__sodiuma.crypto_sign_keypair,
	crypto_sign: globalThis.__s77rt__sodiuma.crypto_sign,
	crypto_sign_open: globalThis.__s77rt__sodiuma.crypto_sign_open,

	sodium_memcmp: globalThis.__s77rt__sodiuma.sodium_memcmp,
	sodium_bin2hex: globalThis.__s77rt__sodiuma.sodium_bin2hex,
	sodium_hex2bin: globalThis.__s77rt__sodiuma.sodium_hex2bin,
	sodium_base64_encoded_len:
		globalThis.__s77rt__sodiuma.sodium_base64_encoded_len,
	sodium_bin2base64: globalThis.__s77rt__sodiuma.sodium_bin2base64,
	sodium_base642bin: globalThis.__s77rt__sodiuma.sodium_base642bin,
	sodium_increment: globalThis.__s77rt__sodiuma.sodium_increment,
	sodium_add: globalThis.__s77rt__sodiuma.sodium_add,
	sodium_sub: globalThis.__s77rt__sodiuma.sodium_sub,
	sodium_compare: globalThis.__s77rt__sodiuma.sodium_compare,
	sodium_is_zero: globalThis.__s77rt__sodiuma.sodium_is_zero,
	sodium_stackzero: globalThis.__s77rt__sodiuma.sodium_stackzero,
};

export default sodium;
