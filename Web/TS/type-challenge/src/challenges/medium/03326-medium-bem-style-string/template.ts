// type JoinString<F extends string[], L extends string> = F extends [] ? '' : `${L}${F[number]}`;
type JoinString<F extends string[], L extends string> = F["length"] extends 0 ? '' : `${L}${F[number]}`;

// type BEM<
//   B extends string,
//   E extends string[],
//   M extends string[]
// > = E["length"] extends 0
//   ? M["length"] extends 0
//     ? B
//     : `${B}--${M[number]}`
//   : M["length"] extends 0
//   ? `${B}__${E[number]}`
//   : `${B}__${E[number]}--${M[number]}`;

type BEM<
  B extends string,
  E extends string[],
  M extends string[]
> = `${B}${JoinString<E, "__">}${JoinString<M, "--">}`;
