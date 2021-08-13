/*
* ts中的类和es6的类几乎一样
* */
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
    function Person(name, age) {
        this.name = name;
        this.age = age;
    }
    Person.prototype.say = function () {
        console.log("\u6211\u662F" + this.name + ",\u4ECA\u5E74" + this.age + "\u5C81");
    };
    Person.eat = function () {
        console.log("\u6211\u559C\u6B22\u5403" + this.food);
    };
    return Person;
}());
var p = new Person("qsc", 18);
p.say();
Person.food = '茄子';
Person.eat();
var Student = /** @class */ (function (_super) {
    __extends(Student, _super);
    function Student(name, age, book) {
        var _this = _super.call(this, name, age) || this;
        _this.book = book;
        return _this;
    }
    Student.prototype.say = function () {
        console.log("\u6211\u662F" + this.name + ",\u4ECA\u5E74" + this.age + "\u5C81,\u559C\u6B22\u770B" + this.book);
    };
    Student.play = function () {
        console.log("\u559C\u6B22\u73A9" + this.product);
    };
    return Student;
}(Person));
var student = new Student('simon', '18', '小说');
student.say();
Student.product = "乒乓球";
Student.play();
