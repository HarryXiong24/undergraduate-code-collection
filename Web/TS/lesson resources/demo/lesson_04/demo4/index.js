function Person(name, age) {
    this.name = name;
    this.age = age;
    this.run = function() {
        return this.name + '在运动';
    }
}

var p = new Person('张飒', 22);
console.log(p.age);                 // 22
console.log(p.run());               // 张飒在运动

function Stu(name, age) {

}

Stu.prototype = new Person();

var stu = new Stu('赵四', 30);          
console.log(stu.age);                   // undefined
console.log(stu.run());                 // undefined在运动