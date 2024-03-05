type NullString = ' ' | '\t' | '\n'
type Trim<S extends string> = S extends `${NullString}${infer R}` | `${infer R}${NullString}` ? Trim<R> : S;
