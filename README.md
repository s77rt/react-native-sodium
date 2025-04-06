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
console.log("Key:", toHex(key));
console.log("Hash:", toHex(output));
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
console.log("Key:", toHex(key));
console.log("Hash:", toHex(output));
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
console.log("Key:", toHex(k));
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
console.log("Key:", toHex(k));
console.log("Hash:", toHex(output));
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
console.log("Key:", toHex(k));
```

</details>

## License

[MIT](LICENSE)
