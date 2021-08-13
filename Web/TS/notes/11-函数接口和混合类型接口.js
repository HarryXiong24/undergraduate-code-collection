// 函数接口
// 我们除了可以通过接口来限定对象以外，我们还可以使用接口来限定函数
var sum = function (x, y) {
    return x + y;
};
var res = sum(10, 20);
console.log(res);
var getCount = (function () {
    // countInterface 接口要求数据既要是一个没有参数没有返回值的函数 又要是一个拥有count属性的对象
    // fun做为函数的时候符合接口中函数接口的限定 （）：void
    // fun做为对象的时候符合接口中对象属性的限定  count：number
    var fun = function () {
        fun.count++;
        console.log(fun.count);
    };
    fun.count = 0;
    return fun;
})();
getCount();
getCount();
getCount();
