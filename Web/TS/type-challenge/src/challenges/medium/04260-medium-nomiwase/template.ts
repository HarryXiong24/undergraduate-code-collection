type StringToUnion<S extends string> = S extends `${infer T}${infer R}` ? T | StringToUnion<R> : never;

type CombineAll<T extends string, P extends string = T> = T extends P ? CombineOnce<T, CombineAll<Exclude<P, T>>> : never;

type CombineOnce<X extends string, Y extends string> = X | Y | `${X}${Y}` | `${Y}${X}`

type AllCombinations<S extends string> = '' | CombineAll<StringToUnion<S>>
