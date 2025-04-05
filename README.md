A fast cryptography module for React Native using libsodium.

## Installation

```bash
npm install @s77rt/react-native-sodium
```

## Documentation

### crypto_generichash

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
```

## License

[MIT](LICENSE)
