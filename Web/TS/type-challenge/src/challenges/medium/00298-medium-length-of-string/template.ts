type LengthOfString<S extends string, T extends string[] = []> = S extends `${infer L}${infer R}` ? LengthOfString<`${R}`, [...T, L]> : T["length"];
