// use T[number]
// type TupleToUnion<T extends any[]> = T[number & keyof T]

// use infer
type TupleToUnion<T extends any[]> = T extends Array<infer Item> ? Item : never;