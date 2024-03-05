type Mixin<T, P> = {
    [K in keyof (T & P)]: (T & P)[K]
}

type InterKey<T, P> = T extends P ? T : never

interface User {
    name: string
    age: number
    address: string
}

type A = ('name' | 'age') extends string ? true : false
type B = (keyof {
    name: string
    age: number
}) & never

type P = InterKey<'name' | 'unknown', keyof User>

type PartialByKeys<T, K = keyof T> = Mixin<{
    [P in InterKey<keyof T, K>]?: T[P]
}, Omit<T, InterKey<keyof T, K>>>