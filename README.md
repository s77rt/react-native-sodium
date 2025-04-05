A fast cryptography module for React Native using libsodium.

## Features

-   JSI
-   1:1 API compatibility with libsodium

## Installation

```bash
npm install @s77rt/react-native-sodium
```

## Documentation

### crypto_generichash single-part

```js
const textEncoder = new TextEncoder();
const toHex = (uint8Array) =>
	Array.from(uint8Array)
		.map((b) => b.toString(16).padStart(2, "0"))
		.join("");

const output = new Uint8Array(32);
const input = textEncoder.encode("abc");
const key = textEncoder.encode("thekey");
__s77rt__sodiuma.crypto_generichash(
	output.buffer,
	output.buffer.byteLength,
	input.buffer,
	input.buffer.byteLength,
	key.buffer,
	key.buffer.byteLength
);
console.log("Hash:", toHex(output));
// Hash: 5dfe64841b066b33f8504400d7b77475e6e361a7a1a02249a6121aac16d2e8bb
```

### crypto_generichash multi-part

```js
const textEncoder = new TextEncoder();
const toHex = (uint8Array) =>
	Array.from(uint8Array)
		.map((b) => b.toString(16).padStart(2, "0"))
		.join("");

const output = new Uint8Array(32);
const input1 = textEncoder.encode("ab");
const input2 = textEncoder.encode("c");
const key = textEncoder.encode("thekey");
const state = {};
__s77rt__sodiuma.crypto_generichash_init(
	state,
	key.buffer,
	key.buffer.byteLength,
	output.buffer.byteLength
);
__s77rt__sodiuma.crypto_generichash_update(
	state,
	input1.buffer,
	input1.buffer.byteLength
);
__s77rt__sodiuma.crypto_generichash_update(
	state,
	input2.buffer,
	input2.buffer.byteLength
);
__s77rt__sodiuma.crypto_generichash_final(
	state,
	output.buffer,
	output.buffer.byteLength
);
console.log("Hash:", toHex(output));
// Hash: 5dfe64841b066b33f8504400d7b77475e6e361a7a1a02249a6121aac16d2e8bb
```

### crypto_generichash_keygen

```js
const k = new Uint8Array(32);
__s77rt__sodiuma.crypto_generichash_keygen(k.buffer);
```

## License

[MIT](LICENSE)
