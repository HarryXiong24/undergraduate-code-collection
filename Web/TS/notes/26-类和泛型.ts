// 泛型类
class Person<T> {
    arr:T[] = [];
    add(val:T):T{
        this.arr.push(val);
        return val;
    }
    all():T[]{
        return this.arr;
    }
}

let p = new Person();
p.add("abc");
p.add(123);
console.log(p.all());