# TS中的类

## ES5中的类

**最简单的类**

```js
var Person = function () {
    /* 属性 */
    this.name = 'hello';
    this.age = 20;

    /* 方法 */
    this.say = function() {
        return 'say func';
    }
}
var p = new Person();
console.log(p.name);             // hello
console.log(p.say());            // say func
```

**构造函数和原型链里面增加方法**

原型链上面的属性会被多个实例共享，构造函数不会。

```js
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

var p = new Person();
console.log(p.gender);              // male
console.log(p.bye());               // good bye
```

**静态方法**

```js
var Person = function () {
    /* 属性 */
    this.name = 'hello';
    this.age = 20;

    /* 实例方法 */
    this.say = function() {
        return 'say func';
    }
}
/* 静态方法 */
Person.getInfo = function() {
    return 'age = 18';
}

/* 原型链方法 */
Person.prototype.getInfo2 = function() {
    return 'age = 31';
}
console.log(Person.getInfo());   // age = 18
console.log(Person.getInfo2());  // 报错（非静态方法不能不构造对象直接使用）
var p = new Person();
console.log(p.name);             // hello
console.log(p.say());            // say func
```

**ES5中的继承**

原型链+对象冒充的组合继承模式。

**原型链实现继承**

[代码示例](../../demo/lesson_04/demo2/index.js)


```js
// Person类如上

function Stu() {
    Person.call(this);          // 对象冒充实现继承
}

var stu = new Stu();
console.log(stu.say());                     // 对象冒充可以继承构造函数里面的属性和方法，但是没法继承原型链上面的属性和方法
console.log(stu.bye());                     // 报错
```

 原型链实现继承：可以继承构造函数里面的属性和方法，也可以继承原型链上面的属性和方法。

 ```js
function Stu() {
    
}

Stu.prototype = new Person();
var stu = new Stu();
console.log(stu.bye());             // good bye
 ```

 原型链实习继承的问题
 
 [示例代码](../../demo/lesson_04/demo4/index.js)

 ```js
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

var stu = new Stu('赵四', 30);          /* 实例化子类的时候没法给父类传参 */
console.log(stu.age);                   // undefined
console.log(stu.run());                 // undefined在运动
 ```

 原型链+构造函数的组合继承模式

[代码示例](../../demo/lesson_04/demo5/index.js)
 ```js
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

var stu = new Stu('赵四', 30);       
console.log(stu.age);                   // 30
console.log(stu.run());                 // 赵四在运动
console.log(stu.bye());                 // 赵四 good bye
 ```

 原型链+对象冒充继承的另一种方式：

 因为函数冒充可以继承构造函数里面的属性和方法，所以原型链继承的时候无需再次继承构造函数里的属性和方法，只需继承```prototype```的属性和方法。

[代码示例](../../demo/lesson_04/demo6/index.js)
 ```js
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

Stu.prototype = Person.prototype;       /* 只需继承prototype的属性和方法 */

var stu = new Stu('赵四', 30);       
console.log(stu.age);                   // 30
console.log(stu.run());                 // 赵四在运动
console.log(stu.bye());                 // 赵四 good bye
 ```

