# 命名空间

## 概念

**命名空间：**

在代码量较大的情况下，为了避免各种变量命名相冲突，可将相似功能的函数、类、接口等放置到命名空间内。

同Java的包、.Net的命名空间一样，TS的命名空间可以将代码包裹起来，只对外暴露需要在外部访问的对象。命名空间内的对象通过export


**命名空间和模块的区别：**

|名称|区别|
|-|-|
|命名空间|内部模块，主要用于组织代码，避免命名冲突|
|模块|TS的外部模块的简称，侧重代码的复用，一个模块里面可能会有多个命名空间|

## 示例

[代码示例](../../demo/lesson_09/demo1/index.ts)
```ts
namespace A {
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

const d = new A.Dog('来福');
d.eat();                // '来福eat food'
```

## 对外暴露命名空间

`modal.ts`
```ts
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
```

`index.ts`
```ts
import {A} from './modal';

const d = new A.Dog('旺财');
d.eat();                        // '旺财eat food'
```