/*
  功能：定义一个操作数据库的库 支持 Mysql Mssql MongoDb
  要求：Mysql MsSql mongDB 功能一样 都有 add update delete get 方法
  注意：约束统一的规范以及代码重用
  解决方案： 需要约束规范所以要定义接口，需要代码重用所以用到泛型
*/ 

// 泛型接口
interface DBI<T> {
  add (info:T):boolean
  update (info:T, id:number):boolean
  delete (id:number):boolean
  get (id:number):any[]
}

// 定义一个操作mysql的类  注意：要实现泛型接口 这个类也应该是个泛型类
class MysqlDB<T> implements DBI<T> {
  add(info: T): boolean {
    console.log(info)
    return true
  }
  update(info: T, id: number): boolean {
    throw new Error("Method not implemented.");
  }
  delete(id: number): boolean {
    throw new Error("Method not implemented.");
  }
  get(id: number): any[] {
    throw new Error("Method not implemented.");
  }
}

// 定义一个操作mssql数据库的类
class MssqlDb<T> implements DBI<T> {
  add(info: T): boolean {
    throw new Error("Method not implemented.");
  }
  update(info: T, id: number): boolean {
    throw new Error("Method not implemented.");
  }
  delete(id: number): boolean {
    throw new Error("Method not implemented.");
  }
  get(id: number): any[] {
    throw new Error("Method not implemented.");
  }
}

// 操作用户表  定义一个User类和数据表做映射
class Users {
  username:string | undefined;
  password:string | undefined
}

let us = new Users()
us.username = '梨花'
us.password = '123456'

let mysql = new MysqlDB<Users>()
mysql.add(us)