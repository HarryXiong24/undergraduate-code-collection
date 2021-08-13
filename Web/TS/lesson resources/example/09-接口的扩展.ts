// 接口扩展：接口可以继承接口
interface People {
  sleep():void
}

interface Man extends People {
  work():void
}

class Programmer {
  name:string;
  constructor(name:string) {
    this.name = name
  }
  coding(code:string):void {
    console.log(`${this.name} like ${code}`)  
  }
}

// Web类继承Programmer类 同时实现 Man接口
class Web extends Programmer implements Man {
  constructor(name:string) {
    super(name)
  }
  sleep():void {
    console.log(`${this.name}喜欢睡觉`)
    
  }
  work():void {
    console.log(`${this.name}喜欢工作`)
    
  }
}

let ming = new Web('小明')
ming.work()
ming.coding('写js')