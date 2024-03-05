// type Flatten<T extends any[]> = {
//     [P in keyof T] : T[P] extends [infer R] ? R : T[P];
// }

type Flatten<T> = T extends [infer F, ...infer Rest] ? F extends unknown[] ? [...Flatten<F>, ...Flatten<Rest>] : [Flatten<F>, ...Flatten<Rest>] : T;