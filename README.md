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

#### randombytes_random

Returns an unpredictable value between `0` and `0xffffffff` (included).

```js
const rnd = sodium.randombytes_random();
```

#### randombytes_uniform

Returns an unpredictable value between `0` and `upperBound` (excluded).

```js
const upperBound = 100;
const rnd = sodium.randombytes_uniform(upperBound);
```

#### randombytes_buf

Fills `buf` with an unpredictable sequence of `size` bytes.

```js
const buf = new ArrayBuffer(8);
sodium.randombytes_buf(buf, buf.byteLength);
```

#### randombytes_buf_deterministic

Fills `buf` with a predictable sequence of `size` bytes given a `randombytes_SEEDBYTES` bytes long `seed`.

```js
const buf = new ArrayBuffer(8);
const seed = toArrayBuffer("Fennec fox".padEnd(32, "\0"));
sodium.randombytes_buf_deterministic(buf, buf.byteLength, seed);
```

#### randombytes_close

Deallocates the global resources used by the pseudo-random number generator.

```js
randombytes_close();
```

#### randombytes_stir

Reseeds the pseudo-random number generator.

```js
randombytes_stir();
```

### Generic hashing

#### crypto_generichash single-part

```js
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

#### crypto_generichash multi-part

```js
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

#### crypto_generichash_keygen

```js
const k = new ArrayBuffer(32);
sodium.crypto_generichash_keygen(k);
```

## License

[MIT](LICENSE)
