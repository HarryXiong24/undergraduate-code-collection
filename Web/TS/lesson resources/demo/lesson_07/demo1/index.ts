class MinClass<T> {
    public list:T[] = [];

    add(value: T): void {
        this.list.push(value);
    }

    min(): T {
        let minVal = this.list[0];
        for (let i = 0; i < this.list.length; i++) {
            if (minVal > this.list[i]) {
                minVal = this.list[i];
            }
        }
        return minVal;
    }
}

let m1 = new MinClass<number>();            // 实例化类，并且指定了类的T代表的是number类型
// m1.add('ad');                               // 报错
m1.add(1);                                  // 正确
m1.add(99);                                 // 正确
m1.add(2);                                  // 正确
console.log(m1.min());                      // 1

let m2 = new MinClass<string>();            // 实例化类，并且指定了类的T代表的是number类型
m2.add('a');                                // 正确
// m2.add(1);                                  // 报错
m2.add('g');                                // 正确
m2.add('z');                                // 正确
console.log(m2.min());                      // 'a'