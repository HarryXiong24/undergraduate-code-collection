"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var Person = /** @class */ (function () {
    function Person(name) {
        this.name = name;
    }
    Person.prototype.run = function () {
        return this.name + ' is running';
    };
    Person.prototype.getName = function () {
        return this.name;
    };
    return Person;
}());
var p = new Person('张三');
console.log(p.name); // 张三
console.log(p.run()); // 张三 is running
console.log(p.getName()); // 张三
var Stu = /** @class */ (function (_super) {
    __extends(Stu, _super);
    function Stu(name) {
        return _super.call(this, name) || this;
    }
    return Stu;
}(Person));
var stu = new Stu('李四');
console.log(stu.name); // 李四
console.log(stu.run()); // 李四 is running
console.log(stu.getName()); // 李四
