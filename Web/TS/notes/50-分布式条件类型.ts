/*
* 1.条件类型(三目运算)
* 判断前面一个类型是否是后面一个类型或者继承于后面一个类型
* 如果是就返回第一个结果，如果不是就返回第二个结果
* 语法：T extends U？x：y
* */

// type myType<T> = T extends string? string : any;
// type res = myType<boolean>;

/*
* 2.分布式条件类型？
* 被检测类型是一个联合类型的时候，该条件类型就被称之为分布式条件类型
* */
//
// type myType<T> = T extends string? T : number;
// type res = myType<(number | string | boolean)>;

// 从ts中删除可以复制给U的类型 Exclude
// type myType<T,U> = T extends U ? never : T;
// // type res = myType<number, string | number | boolean>;
// type res = Exclude<number, string | number | boolean>;

// 提取T中可以赋值给U的类型 Extract
// type res = Extract<number, string | number | boolean>;

// 从T中删除null和undefined。 NonNullable

// type res= NonNullable<string | number | undefined>;

// 获取函数返回值类型  ReturnType
// type res = ReturnType<() => number>

// 获取一个类的构造函数参数组成的元祖类型 ConstructorParameters
// class Person {
//     constructor(name:string,age:number) {
//     }
// }
// type res = ConstructorParameters<typeof Person>;

// 获取函数的参数类型组成的元祖类型 Parameters

function say(name:string,age:number,gender:boolean) {

}

type res = Parameters<typeof say>