interface Animal {
    name: string;
    eat(str: string): void;
}
class Dog implements Animal {
    name: string;
    constructor(name: string) {
        this.name = name;
    }
    eat():void {
        console.log(this.name + 'eat food');
    }
}
let dog = new Dog('旺财');
dog.eat();                      // 旺财eat food

class Cat implements Animal {
    name: string;
    constructor(name: string) {
        this.name = name;
    }
    eat(food: string): void {
        console.log(this.name + ' eat ' + food);
    }
}
let cat = new Cat('来福');
cat.eat('老鼠');                // 来福 eat 老鼠