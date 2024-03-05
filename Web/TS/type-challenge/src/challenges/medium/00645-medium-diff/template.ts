// type AndPick<O, O1> = Pick<O, Exclude<keyof O, keyof O1>> & Pick<O1, Exclude<keyof O1, keyof O>>
// type Diff<O, O1> = {
//     [P in keyof AndPick<O, O1>]: AndPick<O, O1>[P]
// }

// type Diff<O, O1> = {
//     [P in Exclude<keyof (O & O1), keyof (O | O1)>]: P extends keyof O ? O[P] : P extends keyof O1 ? O1[P] : never;
// }

type Mixin<T, P> = {
    [K in keyof (T & P)]: (T & P)[K]
}
type Diff<O, O1> = Omit<Mixin<O, O1>, keyof (O | O1)>
