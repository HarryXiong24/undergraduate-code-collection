/**
 * 任意值
 * any用来表示可以被赋值为任意类型
 */
//  1 什么是任意类型？
// 普通类型，在赋值过程中改变类型不允许
// let a: string = 'Jeson';
// a = 7;
// any类型，允许赋值过程中被改变为任意类型
var b = true;
b = 'jeson';
// 2 任意的属性和方法
// 在任意值上访问任何属性都是被允许的
// 即使属性不存在也不报错
var c = 'jeson';
console.log(c.myName);
console.log(c.myName.firstName);
// 也允许调用任何方法
// 即使方法不存在也不报错
var d = 'hello';
d.myName(11);
d.myName.good(66);
// 总结： 声明为一个任意类型后，对它的任何操作，返回的内容的类型都是任意值
// 3 未声明类型的变量
// 变量如果在声明的时候，未指定其类型，
// 那么他会被识别为任意值类型
var e;
e = 'hello';
e = true;
e.good(66);
