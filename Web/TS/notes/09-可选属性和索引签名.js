// 需求：如果传递了age就输出完整信息，如果没有传递就显示部分信息
function say(_a) {
    var firstName = _a.firstName, lastName = _a.lastName, age = _a.age;
    console.log("\u563F\u563F\u6211\u662F" + lastName + firstName + age);
}
var obj = {
    firstName: 'shengcheng',
    lastName: 'qi'
};
say(obj);
function demo(_a) {
    var name = _a.name, age = _a.age, gender = _a.gender;
    console.log("\u563F\u563F\u6211\u662F" + name + age);
}
demo({ "name": 'qsc', 'age': 18, "gender": 'man' });
