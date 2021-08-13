/*
  接口的作用：在面向对象的编程中，接口是一种 规范的定义，它定义了行为和动作的规范，在程序设计里面
  接口起到了一种限制和规范的作用，接口定义了某一批类所需要遵守的规范，接口不关心这些类内部状态数据
  也不关心这些类里方法实现的细节，它只规定这批类里面必须提供某些方法，提供这些方法的类就可以满足实
  际需要。Typescipt中的接口类似于java,同时还增加了更灵活的接口类型，包括属性，函数，可索引和类等
*/ 

// 1.属性接口 对json的约束

// ts中自定义方法传入参数对 json 进行约束 (自定义的方法很难进行复用)

// function printLabel (labelInfo: {label:string}):void {
//   console.log(labelInfo)
// }
// // printLabel({name: '张三'}) // 错误写法 
// printLabel({label: '桥本'})  // 正确写法

// 对批量方法传入参数进行约束
// 接口： 行为和动作的规范，对批量方法进行约束

// 这个接口 就是传入对象的约束  属性接口
interface FullName {
  firstName:string;
  secondName:string;
}
function printName (name:FullName):void {
  console.log(`${name.firstName}-----${name.secondName}`)
}

let obj = {  // 传入的参数必须包含 firstName secondName  尽量传入的参数和接口的规定一致
  firstName: '小明',
  secondName: '张小明',
  age: 23 
}
printName(obj)

function printInfo(info:FullName):void {
  console.log(`${info.secondName}今年20了`)
}

let info = {
  firstName: 'lili',
  secondName: 'lihua'
}
printInfo(info)

// 接口： 可选属性
interface StudentInfo {
  name:string;
  age?:number; // 可选属性
}

function getInfos(student:StudentInfo):void {
  if (student.age) {
    console.log(`${student.name}---${student.age}`)
  } else {
    console.log(`${student.name}`)
  }
}

// 参数的顺序可以不一样 但是参数的名称和类型应与接口规定的一致
let s1 = {
  name: 'lihhh',
  age: 11
}
getInfos(s1)