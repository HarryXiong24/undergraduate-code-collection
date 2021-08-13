/*
* 1.什么是抽象类？
* 抽象类是专门用于定义那些不希望被外界直接创建的类的
* 抽象类一般用于定义基类
* 抽象类和接口一样用于约束子类
* */

/*
* 2.抽象类和接口区别？
* 接口中只能定义约束，不能定义具体实现
* 而抽象类中既可以定义约束，又可以定义具体实现
* */

abstract class Person {
    abstract name: string;
    abstract say(): void;
    eat():void{
        console.log(`${this.name}正在吃东西`);
    }
}

class Student extends Person{
    name:string = 'qsc';
    say(): void {
        console.log(`我的名字是${this.name}`);
    }
}

let student = new Student();
student.say();
student.eat();
