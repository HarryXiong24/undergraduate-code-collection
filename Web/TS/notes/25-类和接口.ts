// 类'实现'接口

interface Interface {
    name:string;
    say():void;
}
// 只要实现的某一个接口，那么久必须实现接口中所有的属性和方法

class Person implements Interface{
    name = 'qsc';
    say(): void {
        console.log(this.name);
    }
}

let p = new Person();
p.say();

// 接口继承类

class Human {
    protected name:string = 'qsc';
    age:number = 18;
    say():void{
        console.log(this.name + this.age);
    }
}

// let human = new Human();
// p.say();

/*
* 注意点
* 只要一个接口继承了某个类，那么就会继承这个类中的所有属性和方法
* 但是只会继承属性和方法的声明，不会继承属性和方法的实现
*
* 注意点：
* 如果接口继承的类中包含了protected的属性和方法，那么久只有这个类的子类才能实现这个接口
* */

interface fullName extends Human{
    gender:string;
}

class Student extends Human implements fullName{
    gender = 'male';
    name = 'qsc';
    age = 18;
    say(): void {
        console.log(this.name + this.gender + this.age);
    }
}

let student = new Student();
student.say();