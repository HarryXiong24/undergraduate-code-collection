type Without<T extends unknown[], U extends unknown | unknown[]> = T extends [infer L, ...infer R]
    ? L extends (U extends unknown[] ? U[number] : U)
    ? Without<R, U>
    : [L, ...Without<R, U>]
  : [];
