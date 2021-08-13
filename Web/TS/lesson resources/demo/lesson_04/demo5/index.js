function Person(name, age) {
    this.name = name;
    this.age = age;
    this.run = function() {
        return this.name + '在运动';
    }
}
Person.prototype.bye = function() {
    return this.name + ' good bye';
}

var p = new Person('张飒', 22);
console.log(p.age);                 // 22
console.log(p.run());               // 张飒在运动

function Stu(name, age) {
    Person.call(this, name, age);       /* 对象冒充，实例化子类可以给父类传参 */
}

Stu.prototype = new Person();

var stu = new Stu('赵四', 30);          /* 实例化子类的时候没法给父类传参 */
console.log(stu.age);                   // 30
console.log(stu.run());                 // 赵四在运动
console.log(stu.bye());                 // 赵四 good bye