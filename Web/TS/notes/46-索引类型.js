// 通过[]索引类型访问操作符，我们可以得到某个索引的类型
var Person = /** @class */ (function () {
    function Person() {
    }
    return Person;
}());
/*
* 应用场景
* 需求：获取指定对象部分属性的值，放到数组中返回
* */
var obj = {
    name: 'qsc',
    age: 123,
    gender: true
};
function getValue(obj, keys) {
    var arr = [];
    keys.forEach(function (item) {
        arr.push(obj[item]);
    });
    return arr;
}
var res = getValue(obj, ['name', 'age']);
console.log(res);
