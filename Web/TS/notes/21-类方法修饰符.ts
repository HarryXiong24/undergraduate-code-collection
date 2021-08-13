/*
* public：
* 如果使用public来修饰方法，那么表示这个方法是公开的
* 可以在类的内部使用，也可以在子类中使用，也可以在外部使用
* */

/*
* protected:
* 如果使用protected来修饰方法，表示这个方法是受保护的
* 可以在类中使用，也可以在子类中使用
* */

/*
* private:
* 如果使用private来修饰方法，表示这个方法是私有的
* 可以在类中使用
* */

class Person {
    name:string;
    age:number;
    gender:string;
    constructor(name,age,gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
    protected getName():void{
        console.log(`我是${this.name}`);
    }
    private getAge():void{
        console.log(`age=${this.age}`);
    }
    getGender():void{
        console.log(`gender = ${this.gender}`);
    }
}

class Student extends Person{
    constructor(name,age,gender) {
        super(name,age,gender);
    }
    getName(): void {
        super.getName();
    }
    // getAge(): void {
    //     super.getAge();
    // }
    getGender(): void {
        super.getGender();
    }
}

let p = new Person('qsc',18,'male');
let student = new Student('woftsun',19,'female');
student.getName();
