// ts中的函数
// ts中的函数大部分和js相同
//
// // 命名函数
// function say1(name) {
//     console.log(name);
// }
//
// say1("simon");
//
// // 匿名函数
//
// let say2 = function (gender) {
//     console.log(gender);
// };
//
// say2("man");
//
// // 箭头函数
// let say3 = (age) => {
//     console.log(age);
// };

// 命名函数

function say1(name:string):void {
    console.log(name);
}
say1("woftsun");

// 匿名函数
let say2 = function (gender:string):void {
    console.log(gender);
};
say2("boy");

// 箭头函数
let say3 = (age:number):void => {
    console.log(age);
};

say3(18);