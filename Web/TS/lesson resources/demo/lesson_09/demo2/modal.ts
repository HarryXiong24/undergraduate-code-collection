export namespace A {
    interface Animal {
        name: string;
        eat(str: string): void;
    }
    export class Dog implements Animal {
        name: string;
        constructor(name: string) {
            this.name = name;
        }
        eat():void {
            console.log(this.name + 'eat food');
        }
    }

    export class Cat implements Animal {
        name: string;
        constructor(name: string) {
            this.name = name;
        }
        eat(food: string): void {
            console.log(this.name + ' eat ' + food);
        }
    }
}