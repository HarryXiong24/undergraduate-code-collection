/**
 * 功能：定义一个操作数据库的库，支持MySQL、MsSQL、MongoDB
 * 要求：1.MySQL、MsSQL、MongoDB功能一样，都有add、update、delete、get方法
 * 注意：约束统一的规范，以及代码重用
 * 解决方案：需要约束规范所以要定义接口，需要代码重用所以用到泛型
 *      1.接口：在面向对象的编程中，接口是一种规范的定义，它定义了行为和动作的规范
 *      2.泛型：通俗理解：泛型就是解决类、接口、方法的复用性
 */

 interface DBI<T> {
     add(info: T): boolean;

     update(info: T, id: number): boolean;

     delete(id: number): boolean;

     get(id: number): any[];
 }

 /**
  * 定义一个操作mysql数据库的类 
  * 注意：要实现泛型接口，这个类也应该是一个泛型类
  */

class MySqlDB<T> implements DBI<T> {
    constructor() {
        console.log('数据库建立连接');
    }
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
        const list = [];
        return list;
    }
}

/**
 * 定义一个操作MsSQL数据库的类
 */
class MsSqlDB<T> implements DBI<T> {
    constructor() {
        console.log('数据库建立连接');
    }
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
        const list = [];
        return list;
    }
}

/**
 * 操作用户表 
 * 定义一个User类和数据库表做映射
 */
class User {
    username: string;
    password: string;
}

const user1 = new User();
user1.username = 'hello';
user1.password = '123';
const oMysqlDB = new MySqlDB<User> ();
oMysqlDB.add(user1);

const user2 = new User();
user2.username = 'world';
user2.password = '345';
const oMssqlDb = new MsSqlDB<User> ();
oMssqlDb.add(user2);
