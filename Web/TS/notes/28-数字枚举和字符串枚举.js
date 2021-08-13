/*
* TS中支持两种枚举，一种是数字枚举，一种是字符串枚举
* */
// 1.数字枚举，默认情况下就是数字枚举
var Gender;
(function (Gender) {
    Gender[Gender["male"] = 0] = "male";
    Gender[Gender["female"] = 1] = "female";
})(Gender || (Gender = {}));
console.log(Gender.male);
console.log(Gender.female);
/*
*2.数字枚举的注意点
*
*2-1.数字枚举的取值默认是从0开始的
*2-2.数字枚举的取值可以是字面量，也可以是常量（const），也可以是计算结果
*/
var num = 666;
function fun() {
    return 888;
}
var People;
(function (People) {
    People[People["male"] = num] = "male";
    People[People["female"] = fun()] = "female"; // 如果使用计算结果给前面的枚举值赋值了，那么后面的枚举值也要赋值
})(People || (People = {}));
/*
* 3.枚举反向映射
* 可以根据枚举值获取原始值
* 也可以根据原始值获取枚举值
* */
var Enum;
(function (Enum) {
    Enum[Enum["male"] = 0] = "male";
    Enum[Enum["female"] = 1] = "female";
})(Enum || (Enum = {}));
console.log(Enum.male);
console.log(Enum[Enum.female]);
/*
* 4.字符串枚举
* */
var Person;
(function (Person) {
    Person["male"] = "woftsun";
    Person["female"] = "qsc";
})(Person || (Person = {}));
// 注意点：使用字符串枚举给前面的枚举值赋值时，那么后面的枚举值也必须赋值
console.log(Person.female);
console.log(Person.male);
/*
* 5.字符串枚举注意点
*
* 和数字枚举不一样，字符串枚举不能使用常量或者计算结果给枚举值赋值
* 虽然字符串不能通过常量或者计算结果赋值，但是他可以使用内部的其他枚举值来赋值
* */
var Str;
(function (Str) {
    Str["male"] = "woft";
    Str["female"] = "qsc";
    Str["men"] = "woft";
})(Str || (Str = {}));
console.log(Str.male);
console.log(Str.men);
/*
* 6.异构枚举
*
* 枚举中既包含数字又包含字符串，我们称之为异构枚举
* */
var Sum;
(function (Sum) {
    Sum[Sum["male"] = 6] = "male";
    Sum["female"] = "qsc";
})(Sum || (Sum = {}));
console.log(Sum.male);
console.log(Sum.female);
console.log(Sum);
