/*
* ts中的类和es6的类几乎一样
* */

class Person {
    name:string;
    age:number;   // 和es6相比  需要先定义实例属性，才能使用实例属性
    constructor(name,age) {
        this.name = name;
        this.age = age;
    }
    say():void{
        console.log(`我是${this.name},今年${this.age}岁`);
    }
    static food:string;  // 静态属性
    static eat():void {
        console.log(`我喜欢吃${this.food}`);
    }
}

let p = new Person("qsc",18);
p.say();
Person.food = '茄子';
Person.eat();

class Student extends Person{
    book:string;
    constructor(name,age,book) {
        super(name,age);
        this.book = book;
    }
    say(): void {
        console.log(`我是${this.name},今年${this.age}岁,喜欢看${this.book}`);
    }
    static product:string;  // 静态属性
    static play():void {
        console.log(`喜欢玩${this.product}`);
    }
}

let student = new Student('simon','18','小说');
student.say();
Student.product = "乒乓球";
Student.play();