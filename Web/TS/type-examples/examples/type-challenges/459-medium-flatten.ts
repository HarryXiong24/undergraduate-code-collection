export type Flatten<T> = T extends [infer head, ...infer tail] ? [...Flatten<head>, ...Flatten<tail>] : T extends [] ? [] : [T];