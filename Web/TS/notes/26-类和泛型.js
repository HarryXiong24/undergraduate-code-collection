// 泛型类
var Person = /** @class */ (function () {
    function Person() {
        this.arr = [];
    }
    Person.prototype.add = function (val) {
        this.arr.push(val);
        return val;
    };
    Person.prototype.all = function () {
        return this.arr;
    };
    return Person;
}());
var p = new Person();
p.add("abc");
p.add(123);
console.log(p.all());
