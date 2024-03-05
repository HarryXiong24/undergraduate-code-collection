type isFalsy<T> = T extends (0 | '' | false | [] | Record<string, never>) ? true : false;

// type AnyOf<T extends readonly any[]> = isFalsy<T[number]> extends true ? false : true;

type AnyOf<T extends readonly any[]> = T extends [infer F, ...infer Rest] ? isFalsy<F> extends true ? AnyOf<Rest> : true : false; 