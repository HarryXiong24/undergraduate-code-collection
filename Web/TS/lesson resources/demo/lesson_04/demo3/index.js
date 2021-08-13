var Person = function () {
    /* 属性 */
    this.name = 'hello';
    this.age = 20;

    /* 方法 */
    this.say = function() {
        return 'say func';
    }
}
Person.prototype.gender = 'male';
Person.prototype.bye = function() {
    return 'good bye';
}

Person.getInfo = function() {
    return 'age = 18';
}

function Stu() {
    
}

Stu.prototype = new Person();
var stu = new Stu();
console.log(stu.say());             // say func
console.log(stu.bye());             // good bye
console.log(stu.getInfo());         // 报错