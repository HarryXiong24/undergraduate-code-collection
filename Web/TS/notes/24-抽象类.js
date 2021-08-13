/*
* 1.什么是抽象类？
* 抽象类是专门用于定义那些不希望被外界直接创建的类的
* 抽象类一般用于定义基类
* 抽象类和接口一样用于约束子类
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
/*
* 2.抽象类和接口区别？
* 接口中只能定义约束，不能定义具体实现
* 而抽象类中既可以定义约束，又可以定义具体实现
* */
var Person = /** @class */ (function () {
    function Person() {
    }
    Person.prototype.eat = function () {
        console.log(this.name + "\u6B63\u5728\u5403\u4E1C\u897F");
    };
    return Person;
}());
var Student = /** @class */ (function (_super) {
    __extends(Student, _super);
    function Student() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.name = 'qsc';
        return _this;
    }
    Student.prototype.say = function () {
        console.log("\u6211\u7684\u540D\u5B57\u662F" + this.name);
    };
    return Student;
}(Person));
var student = new Student();
student.say();
student.eat();
