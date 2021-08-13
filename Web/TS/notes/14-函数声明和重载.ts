// ts函数完整格式
// 在ts中函数的完整格式应该是由函数的定义和实现两个部分组成

// 定义一个函数
let addFun:(a:number,b:number) => number;
// 根据定义实现函数
addFun= function (a,b){
    return a + b;
};
let res = addFun(5,6);
console.log(res);

// ts声明
// 先声明一个函数

type fun = (a:number,b:number) => number;
// 再根据声明去实现这个函数
let fun:fun = function (x,y) {
    return x + y;
};
let data = fun(7,8);
console.log(data);

// ts函数重载
// 函数的重载就是同名的函数可以根据不同的参数实现不同的功能

// function getArray(x:number):any[] {
//     let arr = [];
//     for (let i = 0;i < x; i ++) {
//         arr.push(i);
//     }
//     return arr;
// }
//
// function getArray(str:string):string[] {
//     return str.split('');
// }
// 定义函数的重载

function getArray(x:number):string[];
function getArray(x:string):string[];

// 实现函数的重载
function getArray(val:any):any[] {
    if (typeof val === 'string') {
        return val.split('');
    } else {
        let arr = [];
        for (let i = 0;i < val; i ++) {
            arr.push(i);
        }
        return arr;
    }
}
// let req = getArray(6);
let req = getArray("abc");
console.log(req);
