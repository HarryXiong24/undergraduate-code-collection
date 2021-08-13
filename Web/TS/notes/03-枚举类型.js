/*
* 枚举类型是ts为js扩展的一种类型，在原生js中是没有枚举类型的
* 枚举用于表示固定的几个数值
*
* eg： 一年只有四季   人的性别只有男女
* */
var Gender;
(function (Gender) {
    Gender[Gender["man"] = 0] = "man";
    Gender[Gender["women"] = 1] = "women";
})(Gender || (Gender = {}));
;
var val;
val = Gender.man;
val = Gender.women;
// val = 'man';
// val = false;   报错
val = 666; // 不会报错
// 注意点 ts中枚举的底层实现的本质其实就是数值类型，所以赋值一个数值不会报错
console.log(Gender.women);
console.log(Gender.man);
