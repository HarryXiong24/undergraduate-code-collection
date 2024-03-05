// mixin intersection type
type Mixin<T extends {}> = {
    [P in keyof T]: T[P] extends keyof any ? Mixin<T[P]> : T[P]
}
type AppendToObject<T extends {}, U extends keyof any, V> = Mixin<T & {
    [P in U]: V
}>

// type AppendToObject<T extends {}, U extends keyof any, V> = {
//   [P in (keyof T | U)]: P extends keyof T ? T[P] : V
// };

