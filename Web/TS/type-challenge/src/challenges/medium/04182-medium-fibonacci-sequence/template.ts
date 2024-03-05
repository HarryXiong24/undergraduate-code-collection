type Fibonacci<
  T extends number,
  U extends number[] = [1],
  K extends number[] = [],
  O extends number[] = [1]
> = O["length"] extends T ? U["length"] : Fibonacci<T, [...U, ...K], U, [...O, 1]>;
