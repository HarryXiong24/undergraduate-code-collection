/*
* any类型
*
* any表示任意类型，当我们不清楚某个值的具体类型的时候我们就可以使用any
* 一般用于定义一些通用性比较强的变量，或者用于保存从其他框架中获取的不确定类型的值
* 在ts中任何数据类型的值都可以赋值给any类型的变量
*
* */

let val:any = 123;
val = 'abc';
val = false;

/*
* void类型
*
* void类型与any正好相反，表示没有任何类型，一般用于函数返回值
* 在ts中只有null和undefined可以赋值给void类型
* */

function test():void {
    console.log('hello world');
}

test();

let val1:void;
// val1 = 123;   // 报错
// val = 'abc';  // 报错

// 注意点： null和undefined是所有类型的子类型，所以我们可以将null和undefined赋值给任意类型

val1 = undefined;