// 可索引接口：对数组的约束 (不常用)
interface UseArr {
  [index:number]:string
}

let aa:UseArr = ['hhhh', 'sssss']
console.log(aa[0])

// 可索引接口： 对对象的约束  (不常用)
interface UseObj {
  [index:string]:string
}

let ab:UseObj = {
  name: '张三'
}

// 类类型接口：对类的约束和抽象类有点相似  （非常常用）
interface Animal {
  name:string;
  eat(str:string):void
}

// 使用 implements 实现接口
class Bird implements Animal {
  name:string
  constructor(name:string) {
    this.name = name
  }

  eat():void {  // 参数可传可不传 但是必须实现eat()方法
    console.log(`${this.name}爱吃饭`)
  }
}

let bird = new Bird('小花')
bird.eat()