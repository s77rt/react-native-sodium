A fast cryptography module for React Native using libsodium.

## Features

-   JSI
-   1:1 API compatibility with libsodium

## Installation

```bash
npm install @s77rt/react-native-sodium
```

## Documentation

For detailed documentation checkout [libsodium Documentation](https://doc.libsodium.org/).

### Generating random data

#### Random number

```ts
randombytes_random(): number;
```

Returns an unpredictable value between `0` and `0xffffffff` (included).

<details>
<summary>Example</summary>

```ts
const rnd = sodium.randombytes_random();
```

</details>

#### Random number within interval

```ts
randombytes_uniform(upperBound: number): number;
```

Returns an unpredictable value between `0` and `upperBound` (excluded).

<details>
<summary>Example</summary>

```ts
const upperBound = 100;
const rnd = sodium.randombytes_uniform(upperBound);
```

</details>

#### Random byte sequence

```ts
randombytes_buf(buf: ArrayBuffer, size: number): void;
```

Fills `buf` with an unpredictable sequence of `size` bytes.

<details>
<summary>Example</summary>

```ts
const buf = new ArrayBuffer(8);
sodium.randombytes_buf(buf, buf.byteLength);
```

</details>

#### Deterministic random byte sequence

```ts
randombytes_buf_deterministic(buf: ArrayBuffer, size: number, seed: ArrayBuffer): void;
```

Fills `buf` with a predictable sequence of `size` bytes given a `randombytes_SEEDBYTES` bytes long `seed`.

<details>
<summary>Example</summary>

```ts
const buf = new ArrayBuffer(8);
const seed = toArrayBuffer("Fennec fox".padEnd(32, "\0"));
sodium.randombytes_buf_deterministic(buf, buf.byteLength, seed);
```

</details>

#### Generator deallocation

```ts
randombytes_close(): number;
```

Deallocates the global resources used by the pseudo-random number generator.

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

Reseeds the pseudo-random number generator.

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
const output = new ArrayBuffer(32);
const input = toArrayBuffer("abc");
const key = toArrayBuffer("thekey");
sodium.crypto_generichash(
	output,
	output.byteLength,
	input,
	input.byteLength,
	key,
	key.byteLength
);
console.log("Hash:", toHex(output));
// Hash: 5dfe64841b066b33f8504400d7b77475e6e361a7a1a02249a6121aac16d2e8bb
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
const output = new ArrayBuffer(32);
const input1 = toArrayBuffer("ab");
const input2 = toArrayBuffer("c");
const key = toArrayBuffer("thekey");
const state = {};
sodium.crypto_generichash_init(state, key, key.byteLength, output.byteLength);
sodium.crypto_generichash_update(state, input1, input1.byteLength);
sodium.crypto_generichash_update(state, input2, input2.byteLength);
sodium.crypto_generichash_final(state, output, output.byteLength);
console.log("Hash:", toHex(output));
// Hash: 5dfe64841b066b33f8504400d7b77475e6e361a7a1a02249a6121aac16d2e8bb
```

</details>

#### Keygen

```ts
crypto_generichash_keygen(k: ArrayBuffer): void;
```

<details>
<summary>Example</summary>

```ts
const k = new ArrayBuffer(32);
sodium.crypto_generichash_keygen(k);
```

</details>

## License

[MIT](LICENSE)
