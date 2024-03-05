type StringToUnion<T extends string> = T extends `${infer F}${infer Rest}` ? F | StringToUnion<Rest> : never;
