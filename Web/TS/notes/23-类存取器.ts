/*
* 什么是类存取器
* 通过getters/setters来截取对对象成员的访问
* */

class Person {
    _age:number = 0;
    set age(val){
        console.log('进入set age方法');
        if (val < 0) {
            throw new Error('年龄不能小于0');
        }
        this._age = val;
    }
}

let p = new Person();
p.age = 30;