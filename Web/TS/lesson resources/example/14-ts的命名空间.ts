/*
  命名空间和模块的区别
      命名空间：内部模块，主要用于组织代码，避免命名冲突 命名空间中的属性，方法，类是私有的 在命名空间外使用时需要export
      模块：    ts的外部模块的简称，侧重代码的复用，一个模块里可能会有多个命名空间
*/ 

// 命名空间A
namespace A{
  interface Animal {
    name:string,
    eat():void
  }
  
  export class Dog implements Animal {
    name:string
    constructor(name:string) {
      this.name = name
    }
    eat():void {
      console.log(`${this.name}吃狗粮`)
    }
  }

  class Cat implements Animal {
    name:string
    constructor(name:string) {
      this.name = name
    }
    eat():void {
      console.log(`${this.name}吃猫粮`)
    }
  }
}

let dog = new Dog('小狗')
dog.eat()

namespace B {
  interface Animal {
    name:string,
    eat():void
  }
  
  export class Dog implements Animal {
    name:string
    constructor(name:string) {
      this.name = name
    }
    eat():void {
      console.log(`${this.name}吃狗粮`)
    }
  }

  export class Cat implements Animal {
    name:string
    constructor(name:string) {
      this.name = name
    }
    eat():void {
      console.log(`${this.name}吃猫粮`)
    }
  }
}

let cat = new B.Cat('小花')
cat.eat()