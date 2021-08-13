/*
* public(公开的)
* 如果使用public来修饰属性，那么表示这个属性是公开的
* 可以在类的内部使用，也可以在子类中使用，也可以在外部使用
* */

/*
* protected(受保护的)
* 如果使用了protected来修饰属性，那么表示这个属性是受保护的
* 可以在类的内部使用，也可以在子类中使用
* */

/*
* private(私有的)
* 如果使用private来修饰属性，那么表示这个属性是私有的
* 只可以在类的内部中使用
* */

// readonly(只读的)

class Person {
    protected name:string;
    age:number;
    readonly gender:string;
    constructor(name,age,gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
    say():void{
        console.log(`name=${this.name}+age=${this.age}+gender=${this.gender}`);
    }
}

class Student extends Person{
    constructor(name,age,gender) {
        super(name,age,gender);
    }
    // say(): void {
    //     super.say();
    // }
}

let p = new Person('qsc',18,'male');
p.say();
let student = new Student('woftsun',19,'female');
student.say();
console.log(p.gender);