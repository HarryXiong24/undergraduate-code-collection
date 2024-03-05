type isObjectType<T> = T extends object ? T extends Function ? false : true : false;
export type DeepReadonly<obj> = { readonly [key in keyof obj]: isObjectType<obj[key]> extends true ? DeepReadonly<obj[key]> : obj[key] };