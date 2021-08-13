// 3.1 函数的定义

// es5中定义函数的方法
/*
    // 函数声明法
    function run() {
      return 'run'
    }
    // 匿名函数
    var run2 = function() {
      return 'run2'
    }
*/

// ts中定义函数的方法
// 1.函数声明法
function run():string {
  return '333'
}

// 2. 匿名函数法
var fun2 = function():number {
  return 1213
}

// ts中定义方法传参
function getInfo(name:string, age:number):string {
  return `${name}---${age}`
}

// 没有返回值的方法
function fn():void {
  console.log('3333')
}

// 3.2 方法可选参数
// es5中方法的实参和形参可以不一样，但是ts中必须一样，如果不一样就需要配置可选参数
// 注意： 可选参数必须配置到参数的最后面
function getData12(name:string, age?:number):string { // ? 表示 age 可传可不传
  if (age) {
    return `${name}---${age}`
  } else {
    return `${name}---年龄保密`
  }
}

// 3.3 默认参数
// es5中没办法设置默认参数，es6和ts中都可以设置默认参数
function getDatal(name:string, age:number = 29):string { 
  if (age) {
    return `${name}---${age}`
  } else {
    return `${name}---年龄保密`
  }
}

// 3.4 剩余参数 三点运算浮接收形参传过来的值
function sum(a:number, ...result:number[]):number {
  let sum = a
  for (let i = 0; i < result.length; i++) {
    sum += result[i]
  }
  return sum
}
sum(1, 3, 4, 5)

// 3.5 函数重载
// typescript中的重载：通过为同一个函数提供多个返回值类型定义来实现多种功能的目的
// ts为了兼容es5 以及 es6 重载的写法和java中有区别
// es5中出现同名的方法，下面的会替换上面的方法

// ts中的重载
function getName(name:string):string

function getName(age:number):number

function getName(str:any):any {
  if (typeof str === 'string') {
    return 'my name is' + str
  } else {
    return 'i am' + str + 'years old'
  }
}
// alert(getName('lisi'))  // 正确
// alert(getName(23))   // 正确
// alert(getName(true)) // 错误写法

function ass(name:string):string
function ass(name:string, age:number):string
function ass(name:any, age?:any):any {
  if (age) {
    return 'my name is' + name + 'i am' + age + 'years old'
  } else {
    return 'my name is' + name
  }
}