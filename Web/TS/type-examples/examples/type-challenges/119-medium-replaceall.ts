export type ReplaceAll<str extends string, from extends string, to extends string> = from extends "" ? str : str extends `${from}${infer tail}` ? `${to}${ReplaceAll<tail, from, to>}` : str extends `${infer char}${infer rest}` ? `${char}${ReplaceAll<rest, from, to>}` : str;