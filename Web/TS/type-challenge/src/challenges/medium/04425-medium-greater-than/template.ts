type GreaterThan<T extends number, U extends number, K extends unknown[] = []> = K["length"] extends T ? false : K["length"] extends U ? true : GreaterThan<T, U, [...K, unknown]>
