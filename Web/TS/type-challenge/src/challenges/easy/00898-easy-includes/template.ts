type MyEqual<X, Y> =
	(<T>() => T extends X ? true : false) extends
	(<T>() => T extends Y ? true : false) ? true : false;

type Includes<T extends readonly any[], U> = T extends [infer F, ...infer Rest] ? MyEqual<U, F> extends true ? true : Includes<Rest, U> : false;
