type Last<T extends any[]> = T extends [...infer Rest, infer Last] ? Last : never;
