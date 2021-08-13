interface Animal {
    eat():void;
}

interface People extends Animal {
    work(str: string): void;
}

class Male implements People {
    public name: string;
    constructor(name: string) {
        this.name = name;
    }

    eat(): void {
        console.log(this.name + '吃米饭');
    }

    work(): void {
        console.log(this.name + '在城市上班');
    }
}
let male = new Male('旺财');
male.eat();
male.work();

class Stu extends Male implements People {
    constructor(name: string) {
        super(name);
    }

    study(lesson: string) {
        console.log(this.name + '学习' + lesson);
    }
}

let stu = new Stu('来福');
stu.eat();
stu.work();
stu.study('物理');