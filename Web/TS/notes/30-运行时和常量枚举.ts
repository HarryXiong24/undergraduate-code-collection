/*
* 1.运行时枚举
* 枚举在编译之后是一个真实存在的对象，所以在运行时使用
* 而像接口这种只是用来做约束的静态检查的代码，编译之后就不存在了
* */

interface Interface {
    name:string;
    age:number
}

enum Gender {
    male,
    female
}

/*
* 常量枚举
* 普通枚举和常量枚举的区别
* 普通枚举会生成真实存在的对象
* 常量枚举不会生成真实存在的对象，而是利用枚举成员的值直接替换使用到的地方
* */

enum Person {
    male,
    female
}

console.log(Person.male === 0);

const enum Human{
    male,
    female
}
console.log(Human.male === 0);
