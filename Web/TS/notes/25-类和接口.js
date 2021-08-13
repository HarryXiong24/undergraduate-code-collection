// 类'实现'接口
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
// 只要实现的某一个接口，那么久必须实现接口中所有的属性和方法
var Person = /** @class */ (function () {
    function Person() {
        this.name = 'qsc';
    }
    Person.prototype.say = function () {
        console.log(this.name);
    };
    return Person;
}());
var p = new Person();
p.say();
// 接口继承类
var Human = /** @class */ (function () {
    function Human() {
        this.name = 'qsc';
        this.age = 18;
    }
    Human.prototype.say = function () {
        console.log(this.name + this.age);
    };
    return Human;
}());
var Student = /** @class */ (function (_super) {
    __extends(Student, _super);
    function Student() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.gender = 'male';
        _this.name = 'qsc';
        _this.age = 18;
        return _this;
    }
    Student.prototype.say = function () {
        console.log(this.name + this.gender + this.age);
    };
    return Student;
}(Human));
var student = new Student();
student.say();
