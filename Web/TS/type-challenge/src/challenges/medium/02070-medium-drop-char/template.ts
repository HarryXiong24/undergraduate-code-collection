type DropChar<S extends string, C extends string> = C extends '' ? S : S extends `${infer H}${infer T}` ?  H extends C ? `${DropChar<T, C>}` : `${H}${DropChar<T, C>}` : S;
