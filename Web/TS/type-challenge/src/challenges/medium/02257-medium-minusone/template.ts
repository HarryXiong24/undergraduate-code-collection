type Expand<length, Arr extends readonly any[] = []> = Arr['length'] extends length ? Arr : Expand<length, [...Arr, Arr['length']] >

type MinusOne<T extends number> = Expand<T> extends [...infer Rest, infer L] ? L : never;
