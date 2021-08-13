// 1.ts中类的定义
class Person1 {
  name:string; // 属性   前面省略了public关键词
  constructor(name:string) { // 构造函数  实例化类的时候触发的方法
    this.name = name
  }
  getName():string {
    return this.name
  }
  setName(name:string):void {
    this.name = name
  }
}
let p = new Person1('张三')
// alert(p.getName())
p.setName('lisi')
// alert(p.getName())

// ts中实现继承(extends super)

// 父类
class Father {
  public name:string
  constructor(name:string) {
    this.name = name
  }
  run():string {
    return `${this.name}在吃饭`
  }
}

// 子类
class Son extends Father {
  age:number
  constructor(name:string, age:number) {
    super(name)
    this.age = age
  }
  // 当子类和父类拥有相同的方法,在调用时会优先使用子类的方法
  showAge():number {
    return this.age
  }
}

let s = new Son('qiaoben', 23)
// alert(s.run())
// alert(s.showAge())

// 3.类里面的修饰符  typescript里面定义属性的时候给我们提供了三种修饰符
//  public: 共有          在类里面，子类，类外面都可以访问
//  protected： 保护类型   在类里面，子类里面可以访问 在类外部没法访问
//  private: 私有         在类里面可以访问，在子类里面，类外面没法访问
// 属性如果不加修饰符 默认为public