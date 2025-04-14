<div align="center">
	<img alt="logo" src="https://raw.githubusercontent.com/s77rt/react-native-sodium/refs/heads/main/assets/logo.png" />
</div>

---

@s77rt/react-native-sodium is a high-performance cryptography library written in C++ that uses the JavaScript Interface (JSI) to provide access to the Sodium API. [Sodium](https://github.com/jedisct1/libsodium) is a modern, easy-to-use library for encryption, decryption, signatures, password hashing, and more.

## Installation

```bash
npm install @s77rt/react-native-sodium
```

## Usage

For detailed documentation checkout [libsodium Documentation](https://doc.libsodium.org/).

### Initialization

```ts
import sodium from "@s77rt/react-native-sodium";

if (sodium.sodium_init() < 0) {
	throw new Error("Failed to initialize sodium!");
}
```

### Generating random data

#### Random number

```ts
randombytes_random(): number;
```

<details>
<summary>Example</summary>

```ts
const rnd = sodium.randombytes_random();
console.log("Random number:", rnd);
```

</details>

#### Random number within interval

```ts
randombytes_uniform(upperBound: number): number;
```

<details>
<summary>Example</summary>

```ts
const upperBound = 100;
const rnd = sodium.randombytes_uniform(upperBound);
console.log("Random number:", rnd);
```

</details>

#### Random byte sequence

```ts
randombytes_buf(buf: ArrayBuffer, size: number): void;
```

<details>
<summary>Example</summary>

```ts
const buf = new ArrayBuffer(8);
sodium.randombytes_buf(buf, buf.byteLength);
console.log("Random byte sequence:", new Uint8Array(buf));
```

</details>

#### Deterministic random byte sequence

```ts
randombytes_buf_deterministic(buf: ArrayBuffer, size: number, seed: ArrayBuffer): void;
```

<details>
<summary>Example</summary>

```ts
const buf = new ArrayBuffer(8);
const seed = new ArrayBuffer(sodium.randombytes_SEEDBYTES);
new TextEncoder().encodeInto("Couscous", new Uint8Array(seed));
sodium.randombytes_buf_deterministic(buf, buf.byteLength, seed);
console.log("Deterministic random byte sequence:", new Uint8Array(buf));
```

</details>

#### Generator deallocation

```ts
randombytes_close(): number;
```

<details>
<summary>Example</summary>

```ts
randombytes_close();
```

</details>

#### Generator reseeding

```ts
randombytes_stir(): void;
```

<details>
<summary>Example</summary>

```ts
randombytes_stir();
```

</details>

### Public-key cryptography

#### Authenticated encryption

```ts
crypto_box_keypair(pk: ArrayBuffer, sk: ArrayBuffer): number;
crypto_box_easy(c: ArrayBuffer, m: ArrayBuffer, mLen: number, n: ArrayBuffer, pk: ArrayBuffer, sk: ArrayBuffer): number;
crypto_box_open_easy(m: ArrayBuffer, c: ArrayBuffer, cLen: number, n: ArrayBuffer, pk: ArrayBuffer, sk: ArrayBuffer): number;
```

<details>
<summary>Example</summary>

```ts
const alicePK = new ArrayBuffer(sodium.crypto_box_PUBLICKEYBYTES);
const aliceSK = new ArrayBuffer(sodium.crypto_box_SECRETKEYBYTES);
const bobPK = new ArrayBuffer(sodium.crypto_box_PUBLICKEYBYTES);
const bobSK = new ArrayBuffer(sodium.crypto_box_SECRETKEYBYTES);
const nonce = new ArrayBuffer(sodium.crypto_box_NONCEBYTES);
const message = new TextEncoder().encode("Fennec fox").buffer;
const messageL = message.byteLength;
const cipherL = sodium.crypto_box_MACBYTES + messageL;
const cipher = new ArrayBuffer(cipherL);
const decrypted = new ArrayBuffer(messageL);
sodium.crypto_box_keypair(alicePK, aliceSK);
sodium.crypto_box_keypair(bobPK, bobSK);
sodium.randombytes_buf(nonce, nonce.byteLength);
sodium.crypto_box_easy(cipher, message, messageL, nonce, bobPK, aliceSK);
sodium.crypto_box_open_easy(decrypted, cipher, cipherL, nonce, alicePK, bobSK);
console.log("Message:", new Uint8Array(message));
console.log("Cipher:", new Uint8Array(cipher));
console.log("Decrypted:", new Uint8Array(message));
```

</details>

#### Sealed boxes

TODO

### Hashing

#### Generic hashing

##### Single-part

```ts
crypto_generichash(output: ArrayBuffer, outputLen: number, input: ArrayBuffer, inputLen: number, key: ArrayBuffer | null, keyLen: number): number;
```

<details>
<summary>Example</summary>

```ts
const output = new ArrayBuffer(sodium.crypto_generichash_BYTES);
const input = new TextEncoder().encode("Fennec fox").buffer;
const key = new ArrayBuffer(sodium.crypto_generichash_KEYBYTES);
sodium.crypto_generichash_keygen(key);
sodium.crypto_generichash(
	output,
	output.byteLength,
	input,
	input.byteLength,
	key,
	key.byteLength
);
console.log(
	"Key:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(key.byteLength * 2 + 1),
		key.byteLength * 2 + 1,
		key,
		key.byteLength
	)
);
console.log(
	"Hash:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(output.byteLength * 2 + 1),
		output.byteLength * 2 + 1,
		output,
		output.byteLength
	)
);
```

</details>

##### Multi-part

```ts
crypto_generichash_init(state: Record<string, never>, key: ArrayBuffer | null, keyLen: number, outputLen: number): number;
crypto_generichash_update(state: Record<string, never>, input: ArrayBuffer, inputLen: number): number;
crypto_generichash_final(state: Record<string, never>, output: ArrayBuffer, outputLen: number): number;
```

<details>
<summary>Example</summary>

```ts
const output = new ArrayBuffer(sodium.crypto_generichash_BYTES);
const input1 = new TextEncoder().encode("Fennec ").buffer;
const input2 = new TextEncoder().encode("fox").buffer;
const key = new ArrayBuffer(sodium.crypto_generichash_KEYBYTES);
const state = {};
sodium.crypto_generichash_keygen(key);
sodium.crypto_generichash_init(state, key, key.byteLength, output.byteLength);
sodium.crypto_generichash_update(state, input1, input1.byteLength);
sodium.crypto_generichash_update(state, input2, input2.byteLength);
sodium.crypto_generichash_final(state, output, output.byteLength);
console.log(
	"Key:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(key.byteLength * 2 + 1),
		key.byteLength * 2 + 1,
		key,
		key.byteLength
	)
);
console.log(
	"Hash:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(output.byteLength * 2 + 1),
		output.byteLength * 2 + 1,
		output,
		output.byteLength
	)
);
```

</details>

##### Keygen

```ts
crypto_generichash_keygen(k: ArrayBuffer): void;
```

<details>
<summary>Example</summary>

```ts
const k = new ArrayBuffer(sodium.crypto_generichash_KEYBYTES);
sodium.crypto_generichash_keygen(k);
console.log(
	"Key:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(k.byteLength * 2 + 1),
		k.byteLength * 2 + 1,
		k,
		k.byteLength
	)
);
```

</details>

#### Short-input hashing

##### Short hash

```ts
crypto_shorthash(output: ArrayBuffer, input: ArrayBuffer, inputLen: number, k: ArrayBuffer): number;
```

<details>
<summary>Example</summary>

```ts
const output = new ArrayBuffer(sodium.crypto_shorthash_BYTES);
const input = new TextEncoder().encode("Fennec fox").buffer;
const k = new ArrayBuffer(sodium.crypto_shorthash_KEYBYTES);
sodium.crypto_shorthash_keygen(k);
sodium.crypto_shorthash(output, input, input.byteLength, k);
console.log(
	"Key:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(k.byteLength * 2 + 1),
		k.byteLength * 2 + 1,
		k,
		k.byteLength
	)
);
console.log(
	"Hash:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(output.byteLength * 2 + 1),
		output.byteLength * 2 + 1,
		output,
		output.byteLength
	)
);
```

</details>

##### Keygen

```ts
crypto_shorthash_keygen(k: ArrayBuffer): void;
```

<details>
<summary>Example</summary>

```ts
const k = new ArrayBuffer(sodium.crypto_shorthash_KEYBYTES);
sodium.crypto_shorthash_keygen(k);
console.log(
	"Key:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(k.byteLength * 2 + 1),
		k.byteLength * 2 + 1,
		k,
		k.byteLength
	)
);
```

</details>

### Padding

#### Pad

```ts
sodium_pad(paddedBufLenP: ArrayBuffer, buf: ArrayBuffer, unpaddedBufLen: number, blockSize: number, maxBufLen: number): number;
```

<details>
<summary>Example</summary>

```ts
const paddedBufLenP = new ArrayBuffer(8); // 8 bytes are needed to store a size_t number
const buf = new ArrayBuffer(64);
const message = new TextEncoder().encode("Fennec fox");
new Uint8Array(buf).set(message);
const unpaddedBufLen = message.byteLength;
const blockSize = 16;
sodium.sodium_pad(
	paddedBufLenP,
	buf,
	unpaddedBufLen,
	blockSize,
	buf.byteLength
);
const paddedBufLen = Number(new DataView(paddedBufLenP).getBigUint64(0, true)); // Safe as long as you are not working with a 9PB data
console.log("Padded buf:", new Uint8Array(buf.slice(0, paddedBufLen)));
```

</details>

#### Unpad

```ts
sodium_unpad(unpaddedBufLenP: ArrayBuffer, buf: ArrayBuffer, paddedBufLen: number, blockSize: number): number;
```

<details>
<summary>Example</summary>

```ts
const unpaddedBufLenP = new ArrayBuffer(8); // 8 bytes are needed to store a size_t number
const buf = new Uint8Array([
	70, 101, 110, 110, 101, 99, 32, 102, 111, 120, 128, 0, 0, 0, 0, 0,
]).buffer;
const blockSize = 16;
sodium.sodium_unpad(unpaddedBufLenP, buf, buf.byteLength, blockSize);
const unpaddedBufLen = Number(
	new DataView(unpaddedBufLenP).getBigUint64(0, true) // Safe as long as you are not working with a 9PB data
);
console.log("Unpadded buf:", new Uint8Array(buf.slice(0, unpaddedBufLen)));
```

</details>

### Helpers

#### Constant-time test for equality

```ts
sodium_memcmp(b1_: ArrayBuffer, b2_: ArrayBuffer, len: number): number;
```

<details>
<summary>Example</summary>

```ts
const b1_ = new Uint8Array([7, 7, 1, 2]).buffer;
const b2_ = new Uint8Array([7, 7, 100, 200]).buffer;
console.log("isEqual:", sodium.sodium_memcmp(b1_, b2_, 2) === 0);
```

</details>

#### Hexadecimal encoding/decoding

```ts
sodium_bin2hex(hex: ArrayBuffer, hexMaxLen: number, bin: ArrayBuffer, binLen: number): string;
sodium_hex2bin(bin: ArrayBuffer, binMaxLen: number, hex: string, hexLen: number, ignore: string | null, binLen: ArrayBuffer, hexEnd: ArrayBuffer | null): number;
```

<details>
<summary>Example 1 (encoding)</summary>

```ts
const bin = new Uint8Array([0, 255, 0, 255]).buffer;
console.log(
	"Hex:",
	sodium.sodium_bin2hex(
		new ArrayBuffer(bin.byteLength * 2 + 1), // Each byte is encoded into two characters, plus one for the null character
		bin.byteLength * 2 + 1,
		bin,
		bin.byteLength
	)
);
```

</details>

<details>
<summary>Example 2 (decoding)</summary>

```ts
const hex = "00ff00ff";
const bin = new ArrayBuffer(hex.length / 2); // Every two characters fit into a single byte
sodium.sodium_hex2bin(
	bin,
	bin.byteLength,
	hex,
	hex.length,
	null,
	new ArrayBuffer(8), // 8 bytes are needed to store a size_t number, not used in this example
	null
);
console.log("Binary:", new Uint8Array(bin));
```

</details>

#### Base64 encoding/decoding

```ts
sodium_base64_encoded_len(binLen: number, variant: number): number;
sodium_bin2base64(b64: ArrayBuffer, b64MaxLen: number, bin: ArrayBuffer, binLen: number, variant: number): string;
sodium_base642bin(bin: ArrayBuffer, binMaxLen: number, b64: string, b64Len: number, ignore: string | null, binLen: ArrayBuffer, b64End: ArrayBuffer | null, variant: number): number;
```

<details>
<summary>Example 1 (encoding)</summary>

```ts
const variant = sodium.sodium_base64_VARIANT_ORIGINAL;
const bin = new Uint8Array([0, 255, 0, 255]).buffer;
const b64Len = sodium.sodium_base64_encoded_len(bin.byteLength, variant);
console.log(
	"Base64:",
	sodium.sodium_bin2base64(
		new ArrayBuffer(b64Len),
		b64Len,
		bin,
		bin.byteLength,
		variant
	)
);
```

</details>

<details>
<summary>Example 2 (decoding)</summary>

```ts
const variant = sodium.sodium_base64_VARIANT_ORIGINAL;
const b64 = "AP8A/w==";
const bin = new ArrayBuffer(Math.ceil((b64.length / 4) * 3)); // Bin will take at most (b64.length / 4) * 3 bytes. Use binLen to get the exact length
const binLen = new ArrayBuffer(8); // 8 bytes are needed to store a size_t number
sodium.sodium_base642bin(
	bin,
	bin.byteLength,
	b64,
	b64.length,
	null,
	binLen,
	null,
	variant
);
const binLenAsNumber = Number(new DataView(binLen).getBigUint64(0, true)); // Safe as long as you are not working with a 9PB data
console.log("Binary:", new Uint8Array(bin.slice(0, binLenAsNumber)));
```

</details>

#### Large numbers arithmetic operations

```ts
sodium_increment(n: ArrayBuffer, nLen: number): void;
sodium_add(a: ArrayBuffer, b: ArrayBuffer, len: number): void;
sodium_sub(a: ArrayBuffer, b: ArrayBuffer, len: number): void;
sodium_compare(b1_: ArrayBuffer, b2_: ArrayBuffer, len: number): number;
```

<details>
<summary>Example</summary>

```ts
const a = new Uint8Array(16).fill(255, 0, 10).buffer; // a=1208925819614629174706175
const b = new Uint8Array(16).fill(255, 0, 10).buffer; // b=1208925819614629174706175
console.log("Comparison", sodium.sodium_compare(a, b, a.byteLength));
sodium.sodium_increment(a, a.byteLength);
console.log("Comparison", sodium.sodium_compare(a, b, a.byteLength));
sodium.sodium_sub(a, b, a.byteLength);
console.log("Comparison", sodium.sodium_compare(a, b, a.byteLength));
```

</details>

#### Testing for all zeros

```ts
sodium_is_zero(n: ArrayBuffer, nLen: number): number;
```

<details>
<summary>Example</summary>

```ts
const n = new ArrayBuffer(8);
console.log("isZero", sodium.sodium_is_zero(n, n.byteLength) === 1);
```

</details>

#### Clearing the stack

```ts
sodium_stackzero(len: number): void;
```

<details>
<summary>Example</summary>

```ts
sodium.sodium_stackzero(4);
```

</details>

## FAQ

**Q: Why functions that take `char*` parameters sometimes use `ArrayBuffer` and other times use `string`?**

**A:** If the input is encoding-dependant an `ArrayBuffer` is used and it's the responsibility of the user to choose the desired encoding. You can use [TextEncoder](https://developer.mozilla.org/en-US/docs/Web/API/TextEncoder/TextEncoder) to generate an array buffer with UTF-8 encoding. On the other hand if the input is guaranteed to be representable in ASCII then it will be interpreted as ASCII and a `string` is used.

If the input is meant to be written into then an `ArrayBuffer` must be used since `string`s are immutable.

**Q: Why are some libsodium functions not implemented?**

**A:** This library aims to provide a 1:1 libsodium compatibility however functions are implemented progressively and per priority and needs. Feel free to [submit an issue](https://github.com/s77rt/react-native-sodium/issues/new) for prioritization.

PRs are welcome!

## License

[MIT](LICENSE)
