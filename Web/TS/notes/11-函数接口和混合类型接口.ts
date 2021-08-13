// 函数接口
// 我们除了可以通过接口来限定对象以外，我们还可以使用接口来限定函数

interface sum {
    (a:number,b:number):number
}

let sum:sum = function (x:number,y:number):number {
    return x + y;
};
let res = sum(10,20);
console.log(res);

// 混合类型接口
// 约定的内容中既有对象属性，又有函数

// 要求定义一个函数实现一个变量的累加
// let count = 0;  // 全局变量会污染空间
// function demo() {
//     count ++;
//     console.log(count);
// }
// demo();
// demo();
// demo();

// 在js中函数的本质就是一个对象
// let demo = function () {
//     demo.count ++;
// };
// demo.count = 0;


interface countInterface {
    ():void
    count:number
}
let getCount = (function ():countInterface {
    // countInterface 接口要求数据既要是一个没有参数没有返回值的函数 又要是一个拥有count属性的对象
    // fun做为函数的时候符合接口中函数接口的限定 （）：void
    // fun做为对象的时候符合接口中对象属性的限定  count：number
    let fun = <countInterface>function () {
        fun.count ++;
        console.log(fun.count);
    };
    fun.count = 0;
    return fun;
})();

getCount();
getCount();
getCount();