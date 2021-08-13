// 可选参数
// 需求：要求定义一个函数可以实现2个数或者3个数的加法

// function add(x:number,y:number,z?:number) {
//     return x + y + (z?z:0);
// }
// let res = add(5,6);
// let res1 = add(5,6,7);
// console.log(res1);
// console.log(res);

// 可选参数可以配置函数重载一起使用，这样可以让重载函数更加强大

function add(x:number,y:number):number;
function add(x:number,y:number,z:number):number;
function add(x,y,z?) {
    return x + y +(z?z:0);
}

let res1 = add(1,2);
let res2 = add(1,2,3);
// let res3 = add(1,2,3,4);   // 报错
console.log(res1,res2);

// 注意点：可选参数后面只能写可选参数，可选参数可以是一个也可以是多个

// 默认参数
function fun(x:number,y:number = 10) {
    return x + y;
}

let data1 = fun(10);
let data2 = fun(10,11);
console.log(data1, data2);

// 剩余参数

function demo(x:number,...y:number[]) {
    console.log(x);
    console.log(y);
}

demo(10,20,30,40,50,60);
demo(10,20);