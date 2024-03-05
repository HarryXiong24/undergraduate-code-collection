// tail recursion
// type FlattenOnce<T extends unknown[], U extends unknown[] = []> = T extends [infer F, ...infer R] ? F extends Array<unknown> ? FlattenOnce<R, [...U, ...F]> : FlattenOnce<R, [...U, F]> : U;
// head recursion
type FlattenOnce<T extends unknown[]> = T extends [infer F, ...infer R] ? F extends Array<unknown> ? [...F, ...FlattenOnce<R>] : [F, ...FlattenOnce<R>] : T;

type FlattenDepth<T extends unknown[], D extends number = 1, P extends unknown[] = []> = P["length"] extends D ? T : FlattenOnce<T> extends T ? T : FlattenDepth<FlattenOnce<T>, D, [...P, unknown]>



