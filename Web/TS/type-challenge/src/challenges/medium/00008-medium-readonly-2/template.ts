// generic-parameter-default can make generic optional
// refer (https://www.typescriptlang.org/docs/handbook/release-notes/typescript-2-3.html#generic-parameter-defaults)
type MyReadonly2<T, K extends keyof T = keyof T> = {
	readonly [P in K]: T[P]
} & {
	[P in Exclude<keyof T, K>]: T[P]
}
