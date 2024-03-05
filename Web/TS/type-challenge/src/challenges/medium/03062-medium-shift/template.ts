type Shift<T> = T extends [infer T, ...infer L] ? L : never;
