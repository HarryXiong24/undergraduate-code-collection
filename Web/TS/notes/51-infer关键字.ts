/*
* 1.infer关键字
* 条件类型提供了一个infer关键字，可以让我们在条件类型中定义新的类型
* */

/*
* 需求：定义一个类型，如果传入是数组，就返回数组的元素类型
*       如果传入的是普通类型，则直接返回这个类型
* */

// type myType<T> = T extends any[]? T[number] : T;
// type res = myType<string[]>;
// type res = myType<number>;

type myType<T> = T extends Array<infer U>? U : T;
// type res = myType<string[]>;
type res = myType<number>;
