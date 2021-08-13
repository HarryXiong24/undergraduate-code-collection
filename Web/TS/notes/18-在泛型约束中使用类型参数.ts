/*
* 在泛型约束中使用类型参数？
* 一个泛型被另一个泛型约束，就叫做泛型约束中使用类型参数
* */

// 需求：定义一个函数用于根据指定的key获取对象的value

let getObject = <T,K extends keyof T>(val:T,item:K):any => {
    return val[item];
};

let obj = {
    "a":'1',
    "b":'2',
    "c":'3',
};

let res = getObject(obj,'a');
console.log(res);