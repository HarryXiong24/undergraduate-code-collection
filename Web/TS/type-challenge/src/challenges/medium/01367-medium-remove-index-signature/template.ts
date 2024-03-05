type Primitive<T, P extends keyof T> = (string | symbol) extends T[P] ? never : P;

type RemoveIndexSignature<T> = {
    [P in keyof T as Primitive<T, P>]: T[P]
}
