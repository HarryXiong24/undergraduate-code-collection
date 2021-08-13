// 1.什么是泛型
// 在编写代码的时候我们既要考虑代码的健壮性，又要考虑代码的灵活性和可重用性
// 通过ts的静态检测能让我们编写的代码变的更加健壮，但是在变的健壮的同时却丢失了灵活性和可重用性
// 所以为了解决这个问题ts有了泛型这个概念
// 通过泛型不仅可以让我们的代码变的更加健壮，还能让我们的代码在变的健壮的同时保持灵活性和可重用性
// 需求：定义一个创建数组的方法，可以创建出指定长度的数组，并且可以用任意指定的内容填充这个数组
/*

let getArray = (x:number,y:number = 5):any[] => {
    return new Array(y).fill(x);
};


let res = getArray(66,3);
console.log(res);
*/
var fun = function (val, item) {
    if (item === void 0) { item = 5; }
    var arr = [];
    for (var i = 0; i < item; i++) {
        arr.push(val);
    }
    return arr;
};
var res = fun('abc', 4);
var len = res.map(function (item) {
    console.log(item.length);
});
