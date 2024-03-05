type Reverse<T> = T extends [infer F, ...infer L] ? [...Reverse<L>, F] : T;
