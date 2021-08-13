/*
* Never类型
*
* 表示是那些永远不存在值的类型
* 一般用于抛出异常或者根本不可能有返回值的函数
* */

function demo():never {
    throw new Error("报错了吧");
}
demo();


// Object类型
// 表示一个对象

let obj:object; // 定义一个只能保存对象的变量
// obj = 1; // 报错
obj = {name:'simon', age:11};
console.log(obj);