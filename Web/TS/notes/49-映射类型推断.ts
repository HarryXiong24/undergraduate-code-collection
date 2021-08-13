/*
* 由映射类型进行推断
* 由于Readonly，Partial 和 pick，Record的映射类型，我们可以对映射之后的类型进行拆包
* 还原映射之前的类型，这种操作称之为拆包
* */

interface Interface {
    name:string;
    age:number;
}

type myType<T> = {
    +readonly [P in keyof T]:T[P];
}

type test = myType<Interface>;

type myType3<T> = {
    -readonly [P in keyof T]:T[P];
}

type myType2 = myType3<test>