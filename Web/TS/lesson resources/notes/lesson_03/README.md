# 第三节 TS中的函数

## 函数的定义

> ES5定义函数的方法

1.函数声明法
```js
function run() {
    return 'run';
}
```

2.匿名函数
```js
let run1 = function() {
    return 'run1';
}
```

> TS中定义函数的方法

1.函数声明法
```ts
function run(): string {
    return 'run';
}
```

2.匿名函数
```ts
var func = function(): number {
    return 123;
}
```

## TS中定义方法传参

1.函数声明法
```ts
function getInfo(name: string, age: number): string {
    return `${name} --- ${age}`;
}
```

2.匿名函数
```ts
var func = function(name: string, age: number): string {
    return `${name} --- ${age}`;
}
```

## 方法的可选参数
ES5中方法的实参和形参可以不一样，但是在TS中必须一样，如果不一样就需要配置可选参数。

```ts
function getInfo(name: string, age?: number): string {
    if (age) {
        return `${name} --- ${age}`;
    } else {
        return `${name} --- 年龄保密`;
    }
}
```
**注意**

可选参数必须从形参的末尾开始配置。
```ts
// 错误示例。可选参数必须放在形参末尾
function func(name?: string, age: number): string {
    return 'complete';
}
```

## 默认参数
在ES5中没法设置默认参数，在ES6和TS中都可以设置默认参数。

默认参数也是可选参数。
```ts
function getInfo(name: string, age: number = 20): string {
    return `${name} --- ${age}`;
}

console.log(getInfo('hello'));   // hello --- 20
console.log(getInfo('hello', 99));   // hello --- 99
```

## 剩余参数
使用ES6中的**三点运算符**。
```ts
function sum(...result: number[]): number {
    let sum = 0;
    for (let i = 0; i < result.length; i++) {
        sum += result[i];
    }
    return sum;
}
```

## 函数重载
java中方法的重载：重载是指两个或者两个以上同名函数，但他们的参数不一样，这时会出现函数重载的情况。

TS为了兼容ES5和ES6，重载的写法和java有区别。

TS中方法的重载：通过为一个函数提供多个函数类型定义来实现多种功能的目的。

ES5中出现同名方法，后声明的会覆盖先声明的。

**TS的重载**

形参数量一致时：

[代码示例](../../demo/lesson_03/demo1/index.ts)
```ts
function getInfo(name: string): string;

function getInfo(age: number): string;

function getInfo(str: any): string {
    if (typeof str === 'string') {
        return '姓名：' + str;
    } else if (typeof str === 'number') {
        return '年龄：' + str;
    }
}

console.log(getInfo('hello'));      // 正确，姓名：hello
console.log(getInfo(20));           // 正确，年龄：20
console.log(getInfo(true));         // 错误
```
形参数量不一致时：

[代码示例](../../demo/lesson_03/demo2/index.ts)
```ts
function getInfo(name: string): string;

function getInfo(name: string, age: number): string;

function getInfo(name: string, age?: number): string {
    if (age) {
        return '姓名：' + name + ' 年龄：' + age;
    } else {
        return '姓名：' + name;
    }
}

console.log(getInfo('hello', 20));      // 正确，姓名：hello 年龄：20
console.log(getInfo('hello'));          // 正确，姓名：hello
console.log(getInfo(20));               // 错误
```
