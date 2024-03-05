type Zip<T extends unknown[], P extends unknown[]> = T extends [infer T1, ...infer R1] ? P extends [infer P1, ...infer R2] ? [[T1, P1], ...Zip<R1, R2>] : [] : [];
