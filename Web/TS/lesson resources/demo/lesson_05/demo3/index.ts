class Person {
    public name: string;
    static gender: string = 'male';
    constructor(name: string) {
        this.name = name;
    }
    /* 实例方法 */
    run() {
        return `${this.name} is running`;
    }
    /* 静态方法 */
    static print() {
        return `static function`;
    }
    static printGender() {
        return `this gender is ${Person.gender}`;
    }
}

console.log(Person.print());        // static function
console.log(Person.printGender());