A fast cryptography module for React Native using libsodium.

## Features

-   JSI
-   1:1 API compatibility with libsodium

## Installation

```bash
npm install @s77rt/react-native-sodium
```

## Usage

For detailed documentation checkout [libsodium Documentation](https://doc.libsodium.org/).

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

### Generic hashing

#### Single-part

```ts
crypto_generichash(output: ArrayBuffer, outputLen: number, input: ArrayBuffer, inputLen: number, key: ArrayBuffer, keyLen: number): number;
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

#### Multi-part

```ts
crypto_generichash_init(state: Record<string, never>, key: ArrayBuffer, keyLen: number, outputLen: number): number;
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

#### Keygen

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

### Short-input hashing

#### Short hash

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

#### Keygen

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

### Helpers

#### Constant-time test for equality

```ts
sodium_memcmp(b1_: ArrayBuffer, b2_: ArrayBuffer, len: number): number;
```

#### Hexadecimal encoding/decoding

```ts
sodium_bin2hex(hex: ArrayBuffer, hexMaxLen: number, bin: ArrayBuffer, binLen: number): string;
sodium_hex2bin(bin: ArrayBuffer, binMaxLen: number, hex: string, hexLen: number, ignore: string | null, binLen: ArrayBuffer, hexEnd: ArrayBuffer | null): number;
```

#### Base64 encoding/decoding

```ts
sodium_base64_encoded_len(binLen: number, variant: number): number;
sodium_bin2base64(b64: ArrayBuffer, b64MaxLen: number, bin: ArrayBuffer, binLen: number, variant: number): string;
sodium_base642bin(bin: ArrayBuffer, binMaxLen: number, b64: string, b64Len: number, ignore: string | null, binLen: ArrayBuffer, b64End: ArrayBuffer | null, variant: number): number;
```

#### Large numbers arithmetic operations

```ts
sodium_increment(n: ArrayBuffer, nLen: number): void;
sodium_add(a: ArrayBuffer, b: ArrayBuffer, len: number): void;
sodium_sub(a: ArrayBuffer, b: ArrayBuffer, len: number): void;
sodium_compare(b1_: ArrayBuffer, b2_: ArrayBuffer, len: number): number;
```

#### Testing for all zeros

```ts
sodium_is_zero(n: ArrayBuffer, nLen: number): number;
```

#### Clearing the stack

```ts
sodium_stackzero(len: number): void;
```

## FAQ

**Q: Why functions that take `char*` parameters sometimes use `ArrayBuffer` and other times use `string`?**

**A:** If the input is encoding-dependant an `ArrayBuffer` is used and it's the responsibility of the user to choose the desired encoding. You can use [TextEncoder](https://developer.mozilla.org/en-US/docs/Web/API/TextEncoder/TextEncoder) to generate an array buffer with UTF-8 encoding. On the other hand if the input is guaranteed to be representable in ASCII then it will be interpreted as ASCII and a `string` is used.

If the input is meant to be written into then an `ArrayBuffer` must be used since `string`s are immutable.

## License

[MIT](LICENSE)
