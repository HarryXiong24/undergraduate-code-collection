// type First<T extends any[]> = T extends [] ? never : T[0];

// type First<T extends any[]> = T extends {0: any} ? T[0] : never;

// type First<T extends any[]> = T extends { 0: infer A } ? A : never;

type First<T extends any[]> = T extends [infer First, ...infer Rest] ? First : never;
