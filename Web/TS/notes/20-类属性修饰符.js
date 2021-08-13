/*
* public(公开的)
* 如果使用public来修饰属性，那么表示这个属性是公开的
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
* protected(受保护的)
* 如果使用了protected来修饰属性，那么表示这个属性是受保护的
* 可以在类的内部使用，也可以在子类中使用
* */
/*
* private(私有的)
* 如果使用private来修饰属性，那么表示这个属性是私有的
* 只可以在类的内部中使用
* */
// readonly(只读的)
var Person = /** @class */ (function () {
    function Person(name, age, gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
    Person.prototype.say = function () {
        console.log("name=" + this.name + "+age=" + this.age + "+gender=" + this.gender);
    };
    return Person;
}());
var Student = /** @class */ (function (_super) {
    __extends(Student, _super);
    function Student(name, age, gender) {
        return _super.call(this, name, age, gender) || this;
    }
    Student.prototype.say = function () {
        _super.prototype.say.call(this);
    };
    return Student;
}(Person));
var p = new Person('qsc', 18, 'male');
p.say();
var student = new Student('woftsun', 19, 'female');
student.say();
