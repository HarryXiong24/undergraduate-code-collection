// 可选属性
// 和接口中的可选属性一样，可传可不传的属性

class Person {
    // 注意点：在ts中如果定义了实例属性，那么久必须在构造函数中使用，否则会报错
    name:string;
    age?:number;
    constructor(name,age?) {
        this.name = name;
        this.age = age;
    }
}

let p = new Person('qsc',18);

// 参数属性
// 一句话搞定实例属性的接受和定义

// class Student {
//     name:string;
//     age:number;
//     constructor(name,age) {
//         this.name = name;
//         this.age = age;
//     }
// }
class Student {
    constructor(public name:string,age:number) {
    }
}
let student = new Student('qsc',18);