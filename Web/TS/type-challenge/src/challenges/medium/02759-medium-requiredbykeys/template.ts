type Mixin<T, P> = {
    [K in keyof (T & P)]: (T & P)[K]
}

type RequiredByKeys<T, K = keyof T> = Mixin<{
    [P in Extract<keyof T, K>]-?: T[P]
}, Omit<T, Extract<keyof T, K>>>
