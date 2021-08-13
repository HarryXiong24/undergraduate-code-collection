# 第七节  泛型

## 概念

软件工程中，我们不仅要创建一致的定义良好的API，同时也要考虑可重用性。组件不仅能够支持当前的数据类型，同时也能支持未来的数据类型，这在创建大型系统时为你提供了十分灵活的功能。

在像C#和Java这样的语言中，可以使用泛型来创建可重用的组件，一个组件可以支持多种类型的数据。这样用户就可以以自己的数据类型来使用组件。

通俗理解：泛型就是解决类、接口、方法的复用性以及对不特定数据类型的支持。

只能返回string类型:

```ts
function getData(value: string): string {
    return value;
}
```

同时返回string类型和number类型：（代码冗余）

```ts
function getData1(value: string): string {
    return value;
}

function getData2(value: number): number {
    return value;
}
```
用`any`可以解决这个问题，但是`any`放弃了类型检查。

比如：传入number类型，返回number类型；传入string类型，返回string类型。但是any就不行了。

```ts
function getData(value: any): any {
    return '123';
}
getData(123);
```

泛型：可以支持不特定的数据类型。

要求：传入的参数和返回的参数一致。

```ts
function getData<T> (value: T): T {
    return value;
}
```
`T`表示泛型，具体什么类型是调用这个方法时决定的。（字母可以随便使用，但是需要一致，也可以用别的字母）

```ts
function getData<A> (value: A): A {
    return value;
}
```

## 泛型的函数

```ts
function getData<T> (value: T): T {
    return value;
}
getData<number>(123);           // 123
getData<number>('hello');       // 报错
getData<string>('hello');       // 'hello'
```

## 泛型类

[代码示例](../../demo/lesson_07/demo1/index.ts)
```ts
class MinClass<T> {
    public list:T[] = [];

    add(value: T): void {
        this.list.push(value);
    }

    min(): T {
        let minVal = this.list[0];
        for (let i = 0; i < this.list.length; i++) {
            if (minVal > this.list[i]) {
                minVal = this.list[i];
            }
        }
        return minVal;
    }
}

let m1 = new MinClass<number>();            // 实例化类，并且指定了类的T代表的是number类型
m1.add('ad');                               // 报错
m1.add(1);                                  // 正确
m1.add(99);                                 // 正确
m1.add(2);                                  // 正确
console.log(m1.min());                      // 1

let m2 = new MinClass<string>();            // 实例化类，并且指定了类的T代表的是number类型
m2.add('a');                                // 正确
m2.add(1);                                  // 报错
m2.add('g');                                // 正确
m2.add('z');                                // 正确
console.log(m2.min());                      // 'a'
```

## 泛型接口

### 函数类型接口：
```ts
interface ConfigFn {
    (value1: string, value2: string): string;
}

const setData: ConfigFn = function(value1: string, value2: string): string {
    return value1 + value2;
}
console.log)setData('hello', 'world'));             // helloworld
```

### 泛型接口:

方法一：
[代码示例](../../demo/lesson_07/demo2/index.ts)
```ts
interface ConfigFn {
    <T> (value1: T): T;
}
const setData:ConfigFn = function<T> (value: T): T {
    return value;
}

console.log(setData<string>('hello'));          // 'hello'
console.log(setData<number>(123));              // 123
```

方法二：

[代码示例](../../demo/lesson_07/demo3/index.ts)
```ts
interface ConfigFn<T> {
    (value1: T): T;
}

/* 拆分开来便于理解 */
function setData<T> (value: T): T {
    return value;
}

const mySetData:ConfigFn<number> = setData;

console.log(mySetData(20));             // 20
```

再把拆分部分合并：

```ts
interface ConfigFn<T> {
    (value1: T): T;
}

/* 拆分部分合并 */
const mySetData:ConfigFn<string> = function<T> (value: T): T {
    return value;
}

console.log(mySetData('hello world'));             // 20
```

## 泛型类

1.定义个类

2.把类作为参数来约束数据传入的类型

[代码示例](../../demo/lesson_07/demo4/index.ts)
```ts
class MinClass<T> {
    public list: T[] = [];
    add(value: T): void {
        this.list.push(value);
    }
    min(): T {
        let minNum = this.list[0];
        for (let i = 0; i < this.list.length; i++) {
            if (minNum < this.list[i]) {
                minNum = this.list[i];
            }
        }
        return minNum;
    }
}

const m1 = new MinClass<number> ();
m1.add(1);
m1.add(3);
m1.add(2);
m1.add('123');                  // 报错
console.log(m1.min());          // 1

const m2 = new MinClass<string> ();
m2.add('b');
m2.add('z');
m2.add('a');
console.log(m2.min());          // 'a'
```

## 实例
定义一个操作数据库的库，支持MySQL、MsSQL、MongoDB。

[代码示例](../../demo/lesson_07/demo5/index.ts)

