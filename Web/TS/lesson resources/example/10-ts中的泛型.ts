/* 
  泛型：泛型就是解决 类 接口 方法的复用性，以及对不特定的数据类型的支持
*/

// 6.1 泛型的定义 和泛型的函数
// 泛型： 可以支持不特定的数据类型 要求：传入的参数和返回的参数一致
// T 表示泛型，具体什么类型是调用这个方法时候决定的
function getData<T>(value:T):T {
  return value
}

console.log(getData<number>(123))

// 6.2 泛型类 ：比如有个最小数算法，需要同时支持返回数字和字符串两种类型。 通过类的泛型来实现
class MinClass<T> {
  public list:T[] = []
  add(value:T):void {
    this.list.push(value)
  }
  min():T {
    let minNum = this.list[0]
    for (let i = 1; i < this.list.length; i++) {
      if (this.list[i] < minNum) {
        minNum = this.list[i]
      }
    }
    return minNum
  }
}

let m1 = new MinClass<number>()   // 实例化类 并且指定了类的T代表的是number类型
m1.add(1)
m1.add(0)
m1.add(-1)
console.log(m1.min())

let m2 = new MinClass<string>()  // 指定类的T代表 string 类型
m2.add('a')
m2.add('z')
m2.add('x')
console.log(m2.min())


// class MinClass {
//   public list:number[] = [];
//   add(num:number) {
//     this.list.push(num)
//   }
//   min():number {
//     let minNum = this.list[0]
//     for (let i = 1; i < this.list.length; i++) {
//       if (this.list[i] < minNum) {
//         minNum = this.list[i]
//       }
//     }
//     return minNum
//   }
// }

// let m = new MinClass()
// m.add(2)
// m.add(4)
// m.add(22)
// m.add(44)
// console.log(m.min())

// 6.3 泛型接口

// 第一种写法
interface Config {
  <T>(value:T):T
}

let getDate:Config = function<T>(value:T):T {
  return value
}

console.log(getDate<string>('ssss'))

// 第二种写法
interface ConfigFn<T> {
  (value:T):T
}
function getData1<T>(value:T):T{
  return value
}
let myGet:ConfigFn<string> = getData1
console.log(myGet('11111'))
