// 可选参数
// 需求：要求定义一个函数可以实现2个数或者3个数的加法
function add(x, y, z) {
    return x + y + (z ? z : 0);
}
var res1 = add(1, 2);
var res2 = add(1, 2, 3);
// let res3 = add(1,2,3,4);   // 报错
console.log(res1, res2);
// 注意点：可选参数后面只能写可选参数，可选参数可以是一个也可以是多个
// 默认参数
function fun(x, y) {
    if (y === void 0) { y = 10; }
    return x + y;
}
var data1 = fun(10);
var data2 = fun(10, 11);
console.log(data1, data2);
// 剩余参数
function demo(x) {
    var y = [];
    for (var _i = 1; _i < arguments.length; _i++) {
        y[_i - 1] = arguments[_i];
    }
    console.log(x);
    console.log(y);
}
demo(10, 20, 30, 40, 50, 60);
demo(10, 20);
