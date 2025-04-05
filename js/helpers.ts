const textEncoder = new TextEncoder();

export function toArrayBuffer(input: string): ArrayBuffer {
	return textEncoder.encode(input).buffer;
}

export function toHex(input: ArrayBuffer | Uint8Array): string {
	const uint8Array =
		input instanceof Uint8Array ? input : new Uint8Array(input);

	// @ts-ignore: toHex is WIP https://github.com/tc39/proposal-arraybuffer-base64/issues/51
	if (Uint8Array.prototype.toHex) {
		// @ts-ignore
		return uint8Array.toHex();
	}

	return Array.from(uint8Array)
		.map((b) => b.toString(16).padStart(2, "0"))
		.join("");
}
