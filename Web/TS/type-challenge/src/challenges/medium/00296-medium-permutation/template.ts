// `T extends never` not work, refer https://github.com/type-challenges/type-challenges/issues/8581
// When conditional types act on a generic type, they become distributive when given a union type
// so have to avoid naked type T, use [T]
// type Permutation<T, P = T> = T extends never ? [] : T extends P ? [T, ...Permutation<Exclude<P, T>>] : never;

type Permutation<T, P = T> = [T] extends [never] ? [] : T extends P ? [T, ...Permutation<Exclude<P, T>>] : never;