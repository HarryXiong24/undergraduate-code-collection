/*
  typescript中的数据类

    布尔类型(boolean)
    数字类型(number)
    字符串类型(string)
    数组类型(array)
    元组类型(tuple)
    枚举类型(enum)
    任意类型(any)
    null 和 undefined
    void类型
    never类型
*/ 
// 在ts语法规范中，定义一个变量时 必须指定它的数据类型 赋值时只能赋给这个变量已经定义的数据类型，不能赋值其他的数据类型

// 布尔类型 (boolean)
let flag:boolean = true
flag = false

// 数字类型(number)  在ts中没有对整型和浮点型进行区分 统一为数字类型
let a:number = 123
console.log(a)

// 字符串类型(string)
let str2:string = 'taozi'
str2 = '桃乃木'

// 数组类型(array) ts中定义数组有两种方式

// 1.第一种
let arr:number[] = [1, 2, 3, 5] // 该数组只能存放number类型的数据
let arr1:string[] = ["java", "php"]  // 该数组只能存放string类型的数据

// 2.第二种
let arr2:Array<number> = [1, 3, 4, 6, 7]
let arr3:Array<string> = ["蔡徐坤", "肖战", "王一博"]

// 元组类型(tuple) 属于数组的一种
let arr4:[string, number, boolean] = ["大蛇", 3.12, true]

// 枚举类型(enum) 常用于定义标识符
enum Flag {
  success = 1,
  error = -1
}
let b:Flag = Flag.success
console.log(b)

enum Color {
  red,
  blue = 5,
  pink
}
let c:Color = Color.red
console.log(c)  //输出： 0  (输出索引)
console.log(Color.blue)  // 输出: 5
console.log(Color.pink) // 输出： 6

// 任意类型
let num:any = 123
num = '桥本有菜'
// 任意类型的作用
let box:any = document.getElementById('box')
box.style.color = 'red'

// null 和 undefined  其他(never类型)数据类型的子类型

// let num:number
// console.log(num)  // 输出： undefined 报错

// let num:undefined
// console.log(num)  // 输出: undefined 正确

// let num1:number | undefined
// num1 = 123
// console.log(num) // 输出： 123

// 定义未赋值
let num1:number | undefined
console.log(num1)

// 一个元素可能是 number 类型 / null / undefined
let num2:number | null | undefined
num2 = 34
console.log(num2)

// void类型： typescript中的void表示没有任何类型，一般用于定义方法的时候方法没有返回值

// es5的定义方法
// function run() {
//   console.log('fff')
// }
// run()

// 表示方法没有返回任何类型
// function run():void {
//   console.log('hhhhh')
// }
// run()

// 方法有返回值
function run3():number {
  return 123
}

// never类型： 是其他类型(包括 null 和 undefined) 的子类型 代表从不会出现的值。这意味着声明never的变量只能被never类型所赋值
