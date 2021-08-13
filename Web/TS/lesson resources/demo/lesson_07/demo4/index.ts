class MinClass<T> {
    public list: T[] = [];
    add(value: T): void {
        this.list.push(value);
    }
    min(): T {
        let minNum = this.list[0];
        for (let i = 0; i < this.list.length; i++) {
            if (minNum > this.list[i]) {
                minNum = this.list[i];
            }
        }
        return minNum;
    }
}

const m1 = new MinClass<number> ();
m1.add(1);
m1.add(3);
m1.add(2);
// m1.add('123');                  // 报错
console.log(m1.min());          // 1

const m2 = new MinClass<string> ();
m2.add('b');
m2.add('z');
m2.add('a');
console.log(m2.min());          // 'a'