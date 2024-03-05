// number extends T['length'] -> An array's "length" is number, but a tuple's "length" is a specific number 
type T = [1, 2]["length"]
type A = number[]["length"]

type IsTuple<T> = [T] extends [never]
  ? false
  : T extends readonly unknown[]
  ? number extends T["length"]
    ? false
    : true
  : false;
