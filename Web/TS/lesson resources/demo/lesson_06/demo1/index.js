"use strict";
/* 必须传入对象。包含firstName和secondName */
function printName(name) {
    console.log(name.firstName + '---' + name.secondName);
}
// printName('123');               /* 错误 */
// printName({                     /* 报错 */
//     age: 20,                    // 不能包含age属性，只能包含firstName和secondName
//     firstName: 'hello',
//     secondName: 'world'
// })
var obj = {
    age: 20,
    firstName: 'hello',
    secondName: 'world'
};
printName(obj); /* 正确 */
