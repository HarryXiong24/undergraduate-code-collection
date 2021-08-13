/*
* ts中接口和命名空间是可以充满的，ts会将多个同名的合并为一个
* */

// 1.接口
// interface Interface {
//     name:string
// }
//
// interface Interface {
//     age:number;
// }
//
// class Person implements Interface{
//     name:string;
//     age:number;
// }

// 1.2同名接口如果出现同名函数，那么就会成为一个函数的重载
interface Interface {
    getVal(val:number):number;
}

interface Interface {
    getVal(val:string):number;
}

let obj:Interface = {
    getVal(val: any): number {
        if (typeof val === 'string') {
            return val.length;
        } else {
            return val.toFixed;
        }
    }
};

console.log(obj.getVal('abc'));
