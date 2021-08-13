/*
* 1.什么是映射类型
* 根据旧的类型创建出新的类型，我们称之为映射类型
* */

interface Interface {
    name:string,
    age:number
}

interface Interface2 {
    readonly name:string,
    readonly age:number
}

type myInterface<T> = {
    // [P in keyof T]:T[P];
    // +readonly [P in keyof T]?:T[P];
    - readonly [P in keyof T]: T[P];
};

type myType = myInterface<Interface>

/*
* 我们可以通过+或者—来指定添加还是删除，只读和可选修饰符
*
* 犹豫生成只读属性和可选属性比较常用，所以ts内部已经给我们提供了现成的实现
*
* Readonly（只读属性）/ Partial（可选属性）
* */

type myType2 = Readonly<Interface>;
type myType3 = Partial<Interface2>;