"use strict";
var Person = /** @class */ (function () {
    function Person(name) {
        this.name = name;
    }
    /* 实例方法 */
    Person.prototype.run = function () {
        return this.name + " is running";
    };
    /* 静态方法 */
    Person.print = function () {
        return "static function";
    };
    Person.printGender = function () {
        return "this gender is " + Person.gender;
    };
    Person.gender = 'male';
    return Person;
}());
console.log(Person.print()); // static function
console.log(Person.printGender());
