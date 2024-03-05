// recursively
// keyof Primitive-Type extends never
type DeepReadonly<T> = {
	readonly [P in keyof T] : keyof T[P] extends never ? T[P] : DeepReadonly<T[P]>
}
