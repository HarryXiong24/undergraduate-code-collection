/*
* 1.什么是类型别名
* 类型别名就是给一个类型起个新名字，但是他们都代表同一个类型
* 例如 ：本名交张三，外号就小三，小三就是张三的别名，张三和小三是同一个人
* */

// 给string类型起了一个别名交myString,那么将来无论是mySring还是string都表示string
type myString = string;
let val:myString;
val = '123';
// val = 123;  // 报错
// val = false  //报错


// 类型别名也可以使用泛型
// type myType<T> = {x:T,y:T};
// let value:myType<number>;
// value = {x:123,y:123};
// value = {x:'123',y:'123'};  // 报错

// 接口和类型别名是相互兼容的

type myType = {
    name:string
}
interface Interface {
    name:string
}

let value1:myType = {name:'qsc'};
let value2:Interface = {name:'qsc'};

value1 = value2;
value2 = value1;