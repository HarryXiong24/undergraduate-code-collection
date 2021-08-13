/*
* 1.null和undefined
* ts具有两种特殊的类型，null和undefined，它们分别具有值null和undefined
* */

/*
* 默认情况下我们可以将null和undefined赋值给任意类型
* 默认情况下null和undefined也可以互相赋值
*
* 注意点：在企业开发中，如果不想把null和undefined赋值给其他类型
*       或者不想让null和undefined的互相赋值，那么我们可以开启strictNullChecks
* */

// let val:null;
// let val2:undefined;
// val = val2;
// val2 = val;
// //
// let val3:number;
// val3 = null;
// val3 = undefined;

/*
* 如果我们开启了strictNullChecks，还想把null和undefined赋值给其他类型
* 那么我们就必须在声明的时候使用联合类型
* */

// let val:number;
// val = null;
// val = undefined;

/*
* 对于可选属性和可选参数而言，如果开启了strictNullChecks，那么默认情况下数据类型是联合类型
* */

class Person{
    name?:string
}
function say(age?:number) {

}
