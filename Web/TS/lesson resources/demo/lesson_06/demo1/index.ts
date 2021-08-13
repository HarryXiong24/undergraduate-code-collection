/* 就是传入对象的约束，属性接口 */
interface FullName {
    firstName: string;
    secondName: string;
}

/* 必须传入对象。包含firstName和secondName */
function printName(name: FullName) {
    console.log(name.firstName + '---' + name.secondName);
}

// printName('123');               /* 错误 */
// printName({                     /* 报错 */
//     age: 20,                    // 不能包含age属性，只能包含firstName和secondName
//     firstName: 'hello',
//     secondName: 'world'
// })

const obj = {
    age: 20,
    firstName: 'hello',
    secondName: 'world'
}
printName(obj);                /* 正确 */