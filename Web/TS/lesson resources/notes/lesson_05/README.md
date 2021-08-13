# TS中的类(下)

## TS中定义类

[代码示例](../../demo/lesson_05/demo1/index.ts)
```ts
class Person {
    /* 属性，前面省略了public关键字 */
    name: string;

    /* 构造函数，实例化类的时候调用的函数 */
    constructor(name: string) {
        this.name = name;
    }
}
```

## TS中实现继承(extends、super)

[代码示例](../../demo/lesson_05/demo2/index.ts)

父类和子类有同名方法时，子类方法覆盖父类方法。

## 类里面的修饰符

typescript里面定义属性的时候给我们提供了三种修饰符

|修饰符|说明|
|-|-|
|public|公有类型，在当前类里面、子类、类外面都可以访问|
|protected|保护类型，在当前类里面、子类可以访问，在类外部不能访问|
|private|私有类型，在当前类里面可以访问，子类、类外部不能访问|

属性如果不加修饰符，则默认为public。

## 静态属性、静态方法

ES5中：
```js
function Person() {
    /* 实例方法 */
    this.run = function() {
        console.log('run1');
    }
}

/* 静态方法 */
Person.run2 = function() {
    console.log('run2');
}

var p = new Person();
/* 调用实例方法 */
p.run();
/* 调用静态方法 */
Person.run2();
```

静态方法使用关键字`static`。

[实例代码](../../demo/lesson_05/demo3/index.ts)
```ts
class Person {
    public name: string;
    /* 静态属性 */
    static gender: string = 'male';

    constructor(name: string) {
        this.name = name;
    }
    /* 实例方法 */
    run() {
        return `${this.name} is running`;
    }
    /* 静态方法 */
    static print() {
        return `static function`;
    }
    static printGender() {
        // 这里写成this.gender或者Person.gender都可以
        return `this gender is ${this.gender}`;
    }
}

console.log(Person.print());        // static function
console.log(Person.printGender());
```

静态方法里面没法调用类里面的属性，静态方法只能调用类里面的静态属性。

## 多态

多态：父类定义一个方法不去实现，让继承它的子类去实现，每一个子类有不同的表现。

多态属于继承，是继承的一种表现。

```ts
class Animal{
    public name: string;

    constructor(name: string) {
        this.name = name;
    }
    /* 具体吃什么？继承他的子类去实现 */
    eat() {
        return 'eat function';
    }
}

class Dog extends Animal{
    constructor(name: string) {
        super(name);
    }

    eat() {
        return `${this.name}吃肉`;
    }
}

class Cat extends Animal{
    constructor(name: string) {
        super(name);
    }

    eat() {
        return `${this.name}吃鱼`;
    }
}
```

## 抽象方法、抽象类

typescript中的抽象类：他是提供其他类继承的基类，不能直接被实例化。

用`abstract`关键字定义抽象类和抽象方法，抽象类中的抽象方法不包含具体实现并且必须在派生类中实现。

abstract抽象方法只能放在抽象类中。

抽象类和抽象方法用来定义标准。

```ts
/* 标准：Animal这个类要求它的子类必须包含eat方法 */
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
```