/*
* 1.什么是unknown类型？
* unknown类型是ts3.0中新增的一个顶级类型，被称作安全的any
* */

// 1.任何类型都可以赋值给unknown类型
// let val:unknown;
// val = 123;
// val = '123';
// val = false;

// 2.如果没有类型断言或者基于控制流的类型细化，那么不能将unknown类型赋值给其他类型
// let val:unknown = 123;
// let val2:number =  123;
// // val2 = val   // 报错
// val2 = val as number;   // 类型断言后是ok的
// if (typeof val === "number") {
//     val2 = val;
// }

// 3.如果没有类型断言或基于控制流细的类型细化，那么不能在unknown类型上进行任何操作
// let val:unknown = 123;
// val ++; // 报错
// (val as number) ++;  // 这样就ok

// 4.只能对unknown类型进行相等或者不等操作，不能进行其他操作（因为其他操作没有意义）
// let val1:unknown = 123;
// let val2:unknown = 123;
// console.log(val1 === val2);
// console.log(val1 !== val2);
// console.log(val1 >== val2); // 正常情况下不会报错，但是不推荐 如果想看报错 打开严格模式

// 5.unknown类型与其他任何类型组成的交叉类型最后都是其他类型
// type myType = number & unknown; // number
// type myType = string & unknown;  // string

// 6.unknown除了与any外，与其他任何类型组成的联合类型都是unknown类型
// type myType = number | unknown | string; // unknown
// type myType = unknown | any;  // any

// 7.never类型是unknown类型的子类型
// type myType = never extends unknown ? true : false;

// 8.keyof unknown等于never
// type myType = keyof unknown;

// 9.unknown类型的值不能访问其属性，方法和创建实例
// class Person {
//     name:string = 'qsc';
//     say():void{
//         console.log(this.name);
//     }
// }
//
// let p:unknown = new Person();
// p.say();  // 报错
// console.log(p.name);  // 报错

// 10.使用映射类型时，如果遍历的是unknown类型，那么不会映射任何属性
type myType<T> = {
    [P in keyof T]:T[P];
}
type res = myType<unknown>  // {}

