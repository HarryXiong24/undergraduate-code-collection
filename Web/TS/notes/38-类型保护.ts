/*
* 3.类型保护
* 对于联合类型的变量，在使用的时候如何确切告诉编译器它是哪一种类型
* 通过类型断言或者是类型保护
* */

let getRandom = ():(string|number) => {
    let num = Math.random();
    return (num >= 0.5)? 'abc' : 123.123;
};

let val = getRandom();
// console.log(val);

if ((val as string).length) {
    console.log((val as string).length);
} else {
    console.log((val as number).toFixed());
}
/*
* 虽然通过类型断言可以确切的告诉编译器当前是什么类型
* 但是每一次使用的时候都需要手动的告诉编译器，这样比较麻烦，冗余代码太多了
* */

/*
* 定义一个类型保护函数，这个函数的'返回类型'是一个布尔型
* 这个函数的返回值类型是，传入的参数+ is具体类型
* */

function isString(val:(string|number)):val is string {
    return typeof val === 'string';
}
if (isString(val)) {
    console.log(val.length);
} else {
    console.log(val.toFixed());
}

/*
* 除了通过定义类型保护函数的方式来告诉编译器使用时联合类型的变量具体是什么类型以外
* 我们可以使用typeof来实现类型保护
* 注意点
* 如果使用typeof来实现类型保护，那么只能使用=== 或者！==
* 如果使用typeof来实现类型保护，那么只能保护number string boolean symbol类型
* */

if (typeof val === 'string') {
    console.log(val.length);
} else {
    console.log(val.toFixed());
}

/*除了通过typeof来实现类型保护以外，我们还可以通过instanceof来实现类型保护*/

class Person {
    name:string = 'qsc';
}

class Student {
    age:number = 18;
}

let Obj = ():(Person|Student) => {
    let num = Math.random();
    return (num > 0.5) ? new Person() : new Student();
};

let obj = Obj();
console.log(obj);
if (obj instanceof Person) {
    console.log(obj.name);
} else {
    console.log(obj.age);
}