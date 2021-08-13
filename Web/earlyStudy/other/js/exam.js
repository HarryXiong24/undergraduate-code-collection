
// var a = "asd";
// console.log("hello");


// var i,j;
// for(i = 1; i <= 5; i++){
//     for(j = 1; j <= 5; j++){
//         console.log(i + "*" + j + "=" + i*j);
//     }
//     console.log("<br \>");
// }


// // 构造方法
// function Person(name, sex, age){
//     this.name = name;  // 属性, 也可以写成this.name: name
//     this.sex = sex;
//     this.age = age;

//     // 成员方法
//     this.hello = function(){
//         console.log("hello!");
//     }
// }

// // 原型方法
// Person.prototype.sayName = function(){
//     console.log("I am " + this.name);
// };

// var person = new Person("Harry", "Man", "19");

// // 调用方法
// person.sayName();
// person.hello();

//var arr = new Array();
// var arr = [1,2,3,4];  //也可以创建一个数组
arr[100] = 5;
arr[0] = "to";
console.log(arr.length);

// 遍历
for(var a in arr){
    console.log(arr[a]);
}

var fun = () => console.log("aaa");
let h = 8;