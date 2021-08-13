/*
* 1.除了同名的接口和命名空间可以合并
* 命名空间还可以和同名的类/函数/枚举寒冰
* 命名空间和累合并
* 注意点：类必须定义在命名空间的前面
* */

class Person {
    say():void{
        console.log('say');
    }
}

namespace Person{
    export const hi = ():void => {
        console.log('hi');
    }
}

console.log(Person);