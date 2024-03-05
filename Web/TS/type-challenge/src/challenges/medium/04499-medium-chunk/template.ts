type Chunk<
  T extends unknown[],
  K extends number,
  U extends unknown[] = []
> = U["length"] extends K
? [U, ...Chunk<T, K, []>]
: T extends [infer F, ...infer R]
? Chunk<R, K, [...U, F]>
: U extends []
? [] : [U]
