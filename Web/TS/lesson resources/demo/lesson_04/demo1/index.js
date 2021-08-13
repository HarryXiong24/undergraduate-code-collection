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

console.log(Person.getInfo());

var p = new Person();
console.log(p.name);             // hello
console.log(p.say());            // say func
console.log(p.gender);              // male
console.log(p.bye());               // good bye

