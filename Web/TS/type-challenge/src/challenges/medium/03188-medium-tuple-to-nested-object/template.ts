type TupleToNestedObject<T, U> = T extends [infer F, ...infer L] ? F extends string ? L extends never ? {
    [P in string as F]: U
} : {
    [P in string as F]: TupleToNestedObject<L, U>
}: never : U
