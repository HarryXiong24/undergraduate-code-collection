type PrefixSign<A> = A extends `+${infer R}` ? ['+', R] : A extends `-${infer R}` ? ['-', R] : ['', A];
// type SuffixSign<A> = A extends `${'+' | '-'}${infer L}%` ? [L, '%'] : A extends `${'+' | '-'}${infer L}` ? [L, ''] : A extends `${infer L}%` ? [L, '%'] : [A, '']
type PercentSign<A> = A extends `${infer L}%` ? [L, '%'] : [A, ''];

// type PercentageParser<A extends string> = [PrefixSign<A>[0], ...SuffixSign<A>]
type PercentageParser<A extends string> = [PrefixSign<A>[0], ...PercentSign<PrefixSign<A>[1]>]
