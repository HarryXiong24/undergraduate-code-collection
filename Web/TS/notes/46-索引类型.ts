// 通过[]索引类型访问操作符，我们可以得到某个索引的类型

class Person {
    name:string;
    age:number;
}

type myType = Person['name'];

/*
* 应用场景
* 需求：获取指定对象部分属性的值，放到数组中返回
* */

let obj = {
    name:'qsc',
    age:123,
    gender:true
};

function getValue<T ,K extends keyof T>(obj:T,keys:K[]):T[K][] {
    let arr = [] as T[K][];
    keys.forEach(item => {
        arr.push(obj[item]);
    });
    return arr;
}

let res = getValue(obj,['name','age']);
console.log(res);


// 索引访问操作符注意点
// 不会反悔null/undefined/never类型

interface Interface {
    a:string,
    b:number,
    c:null,
    d:undefined
}

type Type = Interface[keyof Interface]