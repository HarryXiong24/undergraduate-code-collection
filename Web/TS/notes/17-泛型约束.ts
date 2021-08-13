/*
* 什么是泛型
*
* 默认情况下我们可以指定泛型为任意类型
* 但是有些情况下我们需要指定的类型满足某些条件后才能指定
* 那么这个时候我们就可以使用泛型约束
* */

interface Interface {
    length:number
}

let getArr = <T extends Interface>(val:T,item:number = 5):T[] => {
    let arr = [];
    for (let i = 0;i < item; i ++) {
        arr.push(val)
    }
    return arr;
};

let data = getArr('123',5);
