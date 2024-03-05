type Reverse<T extends any[]> = T extends [infer F, ...infer L] ? [...Reverse<L>, F] : T;

type FlipArguments<T> = T extends (...args: infer P) => infer R ? (...args: Reverse<P>) => R : T;
