type Chainable<T extends object = {}> = {
  option<K extends string, V>(key: K, value: V): Chainable<T & {[P in K]: V}>
  get(): T,
}
