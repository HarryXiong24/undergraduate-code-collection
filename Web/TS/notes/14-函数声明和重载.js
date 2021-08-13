// ts函数完整格式
// 在ts中函数的完整格式应该是由函数的定义和实现两个部分组成
// 定义一个函数
var addFun;
// 根据定义实现函数
addFun = function (a, b) {
    return a + b;
};
var res = addFun(5, 6);
console.log(res);
// 再根据声明去实现这个函数
var fun = function (x, y) {
    return x + y;
};
var data = fun(7, 8);
console.log(data);
// 实现函数的重载
function getArray(val) {
    if (typeof val === 'string') {
        return val.split('');
    }
    else {
        var arr = [];
        for (var i = 0; i < val; i++) {
            arr.push(i);
        }
        return arr;
    }
}
// let req = getArray(6);
var req = getArray("abc");
console.log(req);
