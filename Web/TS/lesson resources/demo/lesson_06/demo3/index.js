"use strict";
var Dog = /** @class */ (function () {
    function Dog(name) {
        this.name = name;
    }
    Dog.prototype.eat = function () {
        console.log(this.name + 'eat food');
    };
    return Dog;
}());
var dog = new Dog('旺财');
dog.eat(); // 旺财eat food
var Cat = /** @class */ (function () {
    function Cat(name) {
        this.name = name;
    }
    Cat.prototype.eat = function (food) {
        console.log(this.name + ' eat ' + food);
    };
    return Cat;
}());
var cat = new Cat('来福');
cat.eat('老鼠'); // 来福 eat 老鼠
