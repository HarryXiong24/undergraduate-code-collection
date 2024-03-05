type TrimRight<S extends string, D = ' ' | '\n' | '\t'> = S extends `${infer L}${D}`
	? TrimRight<L, D>
	: S
