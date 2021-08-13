"use strict";
var arr = [123, 'hello'];
// let arr1:Array<number,string> = [123, 'hello'];      // 报错
// let arr2:[number, string] = ['hello', 123];          // 报错
var colors;
(function (colors) {
    colors[colors["red"] = 0] = "red";
    colors[colors["blue"] = 3] = "blue";
    colors[colors["yellow"] = 4] = "yellow";
})(colors || (colors = {}));
;
var c = colors.yellow;
console.log(c); // 4
c = colors.red;
console.log(c); // 0
