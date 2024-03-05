// Union type
// split Union type and extends target one by one
type MyExclude<T, U> = T extends U ? never : T;
