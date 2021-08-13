"use strict";
var A;
(function (A) {
    var Dog = /** @class */ (function () {
        function Dog(name) {
            this.name = name;
        }
        Dog.prototype.eat = function () {
            console.log(this.name + 'eat food');
        };
        return Dog;
    }());
    A.Dog = Dog;
    var Cat = /** @class */ (function () {
        function Cat(name) {
            this.name = name;
        }
        Cat.prototype.eat = function (food) {
            console.log(this.name + ' eat ' + food);
        };
        return Cat;
    }());
    A.Cat = Cat;
})(A || (A = {}));
var d = new A.Dog('来福');
d.eat();
