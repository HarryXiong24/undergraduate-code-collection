type ReplaceAllX<S extends string, From extends string, To extends string> = From extends '' ? S : S extends `${infer L}${From}${infer R}` ? `${ReplaceAllX<`${L}${To}${R}`, From, To>}` : S;
