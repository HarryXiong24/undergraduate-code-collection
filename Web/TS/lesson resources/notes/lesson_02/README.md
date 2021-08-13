# 第二节 TS中的变量类型

**注意：写TS代码必须指定类型。**

## 1.TS中的类型
|名称|写法|备注|
|-|-|-|
|布尔类型|```let a:boolean=true```|
|数字类型|```let a:number=123```|
|字符串类型|```let a:string='hello'```|
|数组类型|1)```number[]```<br>2)```Array<number>```|
|元组类型(tuple)|```[number, string]```|**元组类型也属于数组的一种。**<br>元组类型可以给数组中**每一个位置指定一个类型**|
|枚举类型(enum)|```enum 枚举名{ 标识符[=整型常量], 标识符[=整型常量], ..., 标识符[=整型常量]}```|
|任意类型|```any```|主要用途：用在选择**DOM对象**时|
|null类型|```null```|其他(never)数据类型的子类型|
|undefined类型|```undefined```|其他(never)数据类型的子类型|
|void类型|```void```|表示没有任何类型，一般用于定义方法时方法没有返回值|
|never类型|```never```|包括**null**和**undefined**，代表从不会出现的值。这意味着**声明never的变量只能被never类型所赋值**|

**元组(tuple)类型**
```js
let arr:[number, string] = [123, 'hello'];
let arr1:[number, string] = ['hello', 'world'];      // 报错
let arr2:[number, string] = ['hello', 123];          // 报错
```
**枚举(enum)类型**
```js
enum flag {success=1, error=2};
let result:flag = flag.success;
console.log(result);        // 1
```
如果标识符没有赋值，那么它的值就是下标
```js
enum colors {red, blue, 'yellow'};
let c:colors = colors.blue;
console.log(c);             // 1
```
也可以单独对某一枚举标识符进行赋值
```js
enum colors {red, blue=3, 'yellow'};
let c:colors = colors.blue;
console.log(c);             // 3
```
如果对某一枚举标识符进行赋值之后，其后的枚举标识符的值也会改变
```js
enum colors {red, blue=3, 'yellow'};
let c:colors = colors.yellow;
console.log(c);             // 4
c = colors.red;
console.log(c);             // 0
```

**任意(any)类型**
在使用JS选择DOM对象时，用any指定引用DOM对象的变量类型
```js
var box:any = document.getElementById('box');
box.style.color = 'red';
```

**undefined类型**
声明变量未赋值就使用会出现报错，所以需要指定为undefined类型
```js
let a:number;
console.log(a);         // 报错
```
将变量指定为undefined类型
```js
let a:undefined;
console.log(a);         // 不报错
```

**一个元素可以设置多个类型**
一个元素可能是number、可能是null、可能是undefined
```js
let num:number | null | undefined;
num = 123;
console.log(num);       
```

**void类型**
```js
function run():void {
    console.log('run');
}
run();
```