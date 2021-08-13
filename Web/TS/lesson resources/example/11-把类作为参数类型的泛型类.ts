/*
  定义一个User的类 这个类的作用就是映射数据库字段 然后定义一个 MysqlDb的类 这个类用于操作数据库
  然后把User类作为参数传入到MySqlDb中
*/ 

// 操作数据库的泛型类
class MysqlDb<T> {
  add (info:T):boolean {
    console.log(info)
    return true
  }
  updated (info:T, id:number):boolean {
    console.log(info)
    console.log(id)
    return true
  }
}

// 想给User表增加数据
// 1.定义一个User类和数据库进行映射

class User {
  username:string | undefined;
  password:string | undefined;
}

let u = new User()
u.username = '张三'
u.password = '12233333'

let Db = new MysqlDb<User>()
Db.add(u)

// 2.定义一个ArticleCate类 和数据库进行映射
class ArticleCate {
  title:string | undefined;
  desc:string | undefined;
  status:number | undefined
  constructor(params:{
    title:string | undefined,
    desc:string | undefined,
    status?:number | undefined
  }) {
    this.title = params.title
    this.desc = params.desc
    this.status = params.status
  }
}

// 增加操作
let z = new ArticleCate({
  title:'分类',
  desc:'1111'
})

let Db1 = new MysqlDb<ArticleCate>()
Db1.add(z)