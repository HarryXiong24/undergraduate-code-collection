type ReplaceKeys<U extends {}, T, Y extends {}> = {
    [P in keyof U]: P extends T ? P extends keyof Y ? Y[P] : never : U[P]
}
