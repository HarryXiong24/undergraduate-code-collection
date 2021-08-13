// 静态属性 静态方法
class Person2 {
  public name:string
  static age:number = 20 //静态属性
  constructor(name:string) {
    this.name = name
  }
  run1():void { // 实例方法
    alert(`${this.name}在吃饭`)
  }
  work():void {
    alert(`${this.name}在工作`)
  }
  
  static fly():void {  // 使用static关键字定义静态方法，在静态方法中不能直接调用类里面的属性
    alert(`我${this.age}岁了`) // 但是可以使用静态属性
  }
}

let pe = new Person2('小米')
pe.run1() // 调用实例方法
Person2.fly()  // 调用静态方法
alert(Person2.age) // 调用静态属性

// 2. 多态：父类定义一个方法不去实现，让继承它的子类去实现，每一个子类有不同的表现
// 多态属于继承
class Animal {
  name:string
  constructor(name:string) {
    this.name = name
  }
  eat() {  // 具体吃什么不知道，具体吃什么 让继承它的子类去实现，每一子类表现不一样

  }
}
class Dog extends Animal{
  constructor(name:string) {
    super(name)
  }
  eat():string {
    return `${this.name}吃肉`
  }
}

class Cat extends Animal {
  constructor(name:string) {
    super(name)
  }
  eat():string {
    return `${this.name}吃老鼠`
  }
}

// 3.抽象类/抽象方法
// typescript中的抽象类：它是提供其他类继承的基类，不能直接被实例化
// 用abstract关键字定义抽象类和抽象方法，抽象类中的抽象方法不包含具体实现并且必须在派生类中实现
// abstract抽象方法只能放在抽象类里面

// 抽象类和抽象方法用来定义标准  标准：Botany 这个类要求它的子类必须包含 effect 方法

abstract class Botany { // 使用abstract关键字定义抽象类
  name:string
  constructor(name:string) {
    this.name = name
  }
  abstract effect():any  // 定义抽象方法

}
class Tree extends Botany {
  constructor(name:string) {
    super(name)
  }
  // 抽象类的子类必须实现抽象类里面的抽象方法
  effect():void {
    alert(`${this.name}能遮阳`)
  }
}

class Flower extends Botany {
  constructor(name:string) {
    super(name)
  }
  effect():void {
    alert(`${this.name}能观赏`)
  }
}

let tree = new Tree('树')
tree.effect()
