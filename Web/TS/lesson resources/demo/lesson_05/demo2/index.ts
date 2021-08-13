class Person {
    name: string;

    constructor(name: string) {
        this.name = name;
    }

    run() {
        return this.name + ' is running';
    }

    getName(): string {
        return this.name;
    }
}

let p = new Person('张三');

console.log(p.name);            // 张三
console.log(p.run());           // 张三 is running
console.log(p.getName());       // 张三

class Stu extends Person {
    constructor(name: string) {
        super(name);
    }
}

let stu = new Stu('李四'); 

console.log(stu.name);            // 李四
console.log(stu.run());           // 李四 is running
console.log(stu.getName());       // 李四