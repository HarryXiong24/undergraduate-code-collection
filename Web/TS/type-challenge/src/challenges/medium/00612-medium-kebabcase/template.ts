type KebabCase<S extends string> = S extends `${infer L}${infer R}` ? `${Lowercase<L>}${R extends Uncapitalize<R> ? '' : '-'}${KebabCase<R>}` : S;
