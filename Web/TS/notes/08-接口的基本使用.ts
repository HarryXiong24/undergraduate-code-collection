/*
* 1.什么是接口类型
*
* 和number，string，boolean，enum这些类型一样
* 接口也是一种类型，也是用来约束使用者的
* */

// 定义一个接口类型
interface fullName {
    firstName:string
    lastName:string
}

let obj = {
    firstName:"simon",
    lastName:"qi"
};
// 需求：要求定义一个函数输出一个完整的姓名，这个人的姓和名都必须是字符串


function test({firstName,lastName}:fullName):void {
    console.log(`我的名字是${lastName} ${firstName}`);
}

test(obj);