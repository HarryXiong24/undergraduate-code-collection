type Fill<
  T extends unknown[],
  N,
  Start extends number = 0,
  End extends number = T["length"],
  Counter extends unknown[] = [],
  F = false
> = T extends [infer First, ...infer Rest]
  ? Counter["length"] extends End
    ? T
  : Counter["length"] extends Start
    ? [N, ...Fill<Rest, N, Start, End, [...Counter, unknown], true>]
    : [
        F extends true ? N : First,
        ...Fill<Rest, N, Start, End, [...Counter, unknown], F>,
      ]
  : T;
