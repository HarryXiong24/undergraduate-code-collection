"use strict";
function getInfo(name, age) {
    let txt = '';
    if (age) {
        txt = '姓名：' + name + ',年龄：' + age;
    }
    else {
        txt = '姓名：' + name;
    }
    return txt;
}
console.log(getInfo('hello'));
console.log(getInfo('hello', 20));
// console.log(getInfo(true));
