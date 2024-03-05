type Pop<T extends any[]> = T extends [...infer Rest, infer Last] ? Rest : never;
