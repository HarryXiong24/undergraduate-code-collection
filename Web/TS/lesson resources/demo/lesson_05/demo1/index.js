"use strict";
var Person = /** @class */ (function () {
    function Person(name) {
        this.name = name;
    }
    Person.prototype.run = function () {
        return this.name + ' is running';
    };
    return Person;
}());
var p = new Person('张三');
console.log(p.name);
console.log(p.run());
