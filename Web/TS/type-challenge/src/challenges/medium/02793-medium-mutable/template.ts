type Mutable<T extends Readonly<Record<string, any>> | ReadonlyArray<any>> = {
  -readonly [P in keyof T]: T[P];
};

interface Todo1 {
  title: string;
  description: string;
  completed: boolean;
  meta: {
    author: string;
  };
}
type List = [1, 2, 3];

type A = Todo1 extends {} ? true : false;

type B = List extends {} ? true : false;
