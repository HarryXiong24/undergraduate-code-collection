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

function Stu () {
    Person.call(this);
}

var stu = new Stu();
console.log(stu.say());         // say func
console.log(stu.bye());         // 报错
console.log(Stu.getInfo());     // 报错  