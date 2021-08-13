/*
* 1.什么是接口类型
*
* 和number，string，boolean，enum这些类型一样
* 接口也是一种类型，也是用来约束使用者的
* */
var obj = {
    firstName: "simon",
    lastName: "qi"
};
// 需求：要求定义一个函数输出一个完整的姓名，这个人的姓和名都必须是字符串
function test(_a) {
    var firstName = _a.firstName, lastName = _a.lastName;
    console.log("\u6211\u7684\u540D\u5B57\u662F" + lastName + " " + firstName);
}
test(obj);
