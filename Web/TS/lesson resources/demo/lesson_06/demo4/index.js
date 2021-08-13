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
var Male = /** @class */ (function () {
    function Male(name) {
        this.name = name;
    }
    Male.prototype.eat = function () {
        console.log(this.name + '吃米饭');
    };
    Male.prototype.work = function () {
        console.log(this.name + '在城市上班');
    };
    return Male;
}());
var male = new Male('旺财');
male.eat();
male.work();
var Stu = /** @class */ (function (_super) {
    __extends(Stu, _super);
    function Stu(name) {
        return _super.call(this, name) || this;
    }
    Stu.prototype.study = function (lesson) {
        console.log(this.name + '学习' + lesson);
    };
    return Stu;
}(Male));
var stu = new Stu('来福');
stu.eat();
stu.work();
stu.study('物理');
