/*
* public：
* 如果使用public来修饰方法，那么表示这个方法是公开的
* 可以在类的内部使用，也可以在子类中使用，也可以在外部使用
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
* protected:
* 如果使用protected来修饰方法，表示这个方法是受保护的
* 可以在类中使用，也可以在子类中使用
* */
/*
* private:
* 如果使用private来修饰方法，表示这个方法是私有的
* 可以在类中使用
* */
var Person = /** @class */ (function () {
    function Person(name, age, gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
    Person.prototype.getName = function () {
        console.log("\u6211\u662F" + this.name);
    };
    Person.prototype.getAge = function () {
        console.log("age=" + this.age);
    };
    Person.prototype.getGender = function () {
        console.log("gender = " + this.gender);
    };
    return Person;
}());
var Student = /** @class */ (function (_super) {
    __extends(Student, _super);
    function Student(name, age, gender) {
        return _super.call(this, name, age, gender) || this;
    }
    Student.prototype.getName = function () {
        _super.prototype.getName.call(this);
    };
    Student.prototype.getAge = function () {
        _super.prototype.getAge.call(this);
    };
    Student.prototype.getGender = function () {
        _super.prototype.getGender.call(this);
    };
    return Student;
}(Person));
var p = new Person('qsc', 18, 'male');
var student = new Student('woftsun', 19, 'female');
student.getName();
