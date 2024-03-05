// type ObjectEntries<T> = {
//     [P in keyof T]: [P, T[P]]
// }[keyof T]

type ObjectEntries<T, K = keyof T> = K extends keyof T ? [K, T[K]] : never;