// 只比较实例成员，不比较类的构造函数和静态成员

class Person {
    name:string;
    age:number;
    constructor(name,age) {
    }
}

class People {
    name:string;
    constructor(name) {
    }
}

let p = new Person('qsc',12);
let p1 = new People('qsc');

// p = p1;  // 报错
p1 = p;  // 可多不可少

// 类的私有属性和受保护属性会响应兼容性

// class Student {
//     protected name:string;
//     protected age:number
// }
//
// class Children {
//     protected name:string;
// }
// let student = new Student();
// let child = new Children();
//
// p = a;
// a = p;