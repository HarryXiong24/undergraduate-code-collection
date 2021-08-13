/*
  装饰器：装饰器是一种特殊类型的声明，它能够被附加到类声明，方法，属性或参数上，可以修改类的行为
  通俗的讲装饰器就是一个方法，可以注入到类，方法，属性参数上来扩展类，属性，方法，参数的功能
  常见的装饰器有：类装饰器，属性装饰器，方法装饰器，参数装饰器
  装饰器的写法：普通装饰器(无法传参) 装饰器工厂(可传参)
*/ 

// 1.类装饰器：类装饰器在类声明之前被声明 类装饰器应用于类构造函数 类装饰器应用于类构造函数，修改或替换类定义 传入一个参数
// 1.1 普通装饰器(不可传参)
function logClass (params:any) {
  // console.log(params) // params就是当前类
  params.prototype.apiUrl = 'xxx' //动态扩展的属性
  params.prototype.run = function () { //动态扩展方法
    console.log('爱吃冰激淋')
  }
}

// 用装饰器装饰类
@logClass
class HttpClient {
  constructor() {

  }
  getData() {

  }
}

let http:any = new HttpClient()
console.log(http.apiUrl)
http.run()

// 1.2 装饰器工厂 (可传参)
function logIn (params:string) {
  return function (target:any) {
    // console.log(target)  // 当前类
    // console.log(params)  // 传入的参数
    target.prototype.apiUrl = params
    target.prototype.eat = function ():void {
      console.log('hhhh')
    }
  }
}

@logIn('hello')
class Http {
  constructor() {

  }
  getData() {

  }
}
let h:any = new Http()
console.log(h.apiUrl)
h.eat()

// 1.3 重载类的构造函数和方法
function log (target:any) {
  // console.log(target)
  return class extends target {
    apiUrl:any = '我是修改后的数据'
    getData ():void {
      this.apiUrl = this.apiUrl + 'ssssss'
      console.log(this.apiUrl)
    }
  }
}

@log
class Hp {
  public apiUrl:string | undefined
  constructor () {
    this.apiUrl = '我是构造函数里的apiUrl'
  }
  getData ():void {
    console.log(this.apiUrl)
  }
}

let d:any = new Hp()
d.getData()

// 2.属性装饰器
// 属性装饰器表达式会在运行时当作函数被调用，传入下列两个参数：
//          1. 对于静态成员来说是类的构造函数，对于实例成员是类的原型对象
//          2. 成员的名字

// 类装饰器
function logIns (params:string) {
  return function (target:any) {
    // console.log(target)
    // console.log(params)
  }
}

// 属性装饰器
function logProperty (params:any) {   // params: 传入的参数
  return function(target:any, attr:any) {
    // console.log(target) // 当前类的原型对象
    // console.log(attr)  // 属性名称
    target[attr] = params
  }
}

@logIns('xxxx')
class Https {
  @logProperty('http://www.baidu.com')
  public url:any | undefined
  constructor() {

  }
  getData() {
    console.log(this.url)
  }
}

// 3.方法装饰器
// 它会被应用到方法的属性描述符上，可以用来监视，修改或者替换方法定义
// 方法装饰器会在运行时传入下列三个参数：
//       1. 对于静态成员来说是类的构造函数，对于实例成员是类的原型对象
//       2. 成员的名字
//       3. 成员的属性描述符
function get (params:any) {
  return function (target:any, methodName:any, desc:any) {
    console.log(target) //类的原型对象
    console.log(methodName) // 方法名称
    console.log(desc)     // 方法的描述
    target.run = function ():void {
      console.log('阿三士大夫的')
    }
    // 修改装饰器的方法 把装饰器方法里传入的所有参数改为string类型
    // 1.保存当前的方法
    let oMethod = desc.value
    // 2.修改
    desc.value = function (...args:any[]) {
      args = args.map((value) => {
        return String(value)
      })
      console.log(args)
      oMethod.apply(this, args)
    }
  }
}

class HttpClients {
  public url:any | undefined
  constructor() {

  }
  @get('http://www.google.com')
  getData() {
    console.log(this.url)
  }
}

// 4 装饰器的执行顺序
// 属性装饰器 > 方法装饰器 > 方法参数装饰器 > 类装饰器
// 如果有多个相同的装饰器 它会先执行后面的