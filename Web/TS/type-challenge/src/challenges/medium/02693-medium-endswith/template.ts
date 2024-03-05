type EndsWith<T extends string, U extends string> = T extends `${infer T}${U}` ? true : false;
