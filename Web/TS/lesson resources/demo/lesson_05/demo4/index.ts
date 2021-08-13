abstract class Animal{
    public name: string;
    constructor(name: string) {
        this.name = name;
    }

    abstract eat(): any;
}

/* 抽象类的子类必须实现抽象类里面的抽象方法 */
class Dog extends Animal{
    constructor(name: string) {
        super(name);
    }

    eat() {
        return `${this.name}吃肉`;
    }
}

let dog = new Dog('来福');
console.log(dog.eat());         // 来福吃肉