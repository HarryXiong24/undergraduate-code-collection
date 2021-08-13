# 装饰器

## 概念

装饰器是一种特殊类型的声明，他能够被附加到类声明、方法、属性或参数上，可以修改类的行为。

通俗的讲，装饰器就是一个方法，可以注入到类、方法、属性、参数上来扩展类、属性、方法、参数的功能。

常见的装饰器有：类装饰器、属性装饰器、方法装饰器、参数装饰器

装饰器的写法：普通装饰器（无法传参）、装饰器工厂（可传参）

装饰器是过去几年中js最大的成就之一，已是ES7的标准特性之一。

**注意**

使用装饰器必须要打开`tsconfig.json`中的`experimentalDecorators`和`emitDecoratorMetadata`两项，并设置为`true`。

## 类装饰器

类装饰器在类声明之前被声明（紧靠着类声明）。类装饰器应用于类构造函数，可以用来监视、修改或替换类定义。传入一个参数

### 类装饰器：普通装饰器
[代码示例](../../demo/lesson_10/demo1/index.ts)
```ts
// 类装饰器
function logClass(param: any): void {
    console.log(param);

    // param就是当前类

    param.prototype.apiUrl = '动态扩展的属性';

    param.prototype.run = function() {
        console.log('我是一个run方法');
    }
}

@logClass
class HttpClient {
    constructor() {

    }

    getData():void {

    }
}

const h:any = new HttpClient();
console.log(h.apiUrl);              // '动态扩展的属性'
h.run();                            // '我是一个run方法'
```

### 类装饰器：装饰器工厂

有点类似express中中间件的写法
```ts
function logClass(param: string) {
    return function(target: any) {
        console.log(target);

        console.log(param);

        target.prototype.apiUrl = 'xxxxxxx';
    }
}

@logClass('hello')
class HttpClient {
    constructor() {

    }

    getData() {

    }
}

const h: any = new HttpClient();
console.log(h.apiUrl);              // 'xxxxxxx'
```

### 例子

下面是一个重载构造函数的例子。

类装饰器表达式会在运行时当做函数被调用，类的构造函数作为其唯一的参数。

如果类装饰器返回一个值，他会使用提供的构造函数来替换类的声明。

[代码示例](../../demo/lesson_10/demo2/index.ts)
```ts
function logClass(target: any) {
    return class extends target {
        apiUrl:string = '修改后的str';

        getData() {
            return 'hello world';
        }
    }
}

@logClass
class HttpClient {
    public apiUrl: string;
    constructor() {
        this.apiUrl = '修改前的str';
    }

    getData():string {
        return this.apiUrl;
    }
}

const h = new HttpClient();
console.log(h.apiUrl);                  // '修改后的str'
console.log(h.getData());               // 'hello world'
```

如果使用装饰器进行重载的话，需要把父类中的所有属性、方法全都重载了，不然`@logClass`这一句会报错

## 属性装饰器

属性装饰器表达式会在运行时当做函数被调用，传入下列2个参数：

1.对于静态成员来说是类的构造函数，对于实例成员是类的原型函数

2.成员的名字
```ts
// 类装饰器
function logClass(param: string) {
    return function(target: any) {
        console.log(target);
        console.log(param);
    }
}

// 属性装饰器
function logProperty(param: string) {
    /* target:原型函数   attr:成员名字 */
    return function(target: any, attr: any) {
        console.log(target);            // [Function: HttpClient]
        console.log(attr);              // url

        target[attr] = param;
    }
}

@logClass('xxxx')
class HttpClient{
    @logProperty('www.badu.com')
    public url: any | undefined;

    constructor() {

    }

    getData() {
        return this.url;
    }
}

const h = new HttpClient();
console.log(h.getData());           // 'www.badu.com'
```

## 方法装饰器

他会被应用到方法的属性描述符上，可以用来监视、修改或替换方法定义。

方法装饰器在运行时传入下列3个参数：

1. 对于静态成员来说是类的构造函数，对于实例成员是类的原型对象
2. 成员的名字
3. 成员的属性描述符


方法装饰器一

```ts
// 装饰器
function logMethods(param: any) {
    /**
     * target: 原型对象
     * methodName: 成员的名字
     * desc: 成员的属性描述符 
     */
    return function (target: any, methodName: any, desc: any) {
        console.log(target);
        console.log(methodName);
        console.log(desc.value);

        target.apiUrl = 'xxxx';
        target.run = function() {
            console.log('run');
        }
    }
}

class HttpClient {
    constructor() {

    }

    @logMethods('www.baidu.com')
    getData() {
        console.log(this.url);
    }
}

const h = new HttpClient();
console.log(h.apiUrl);
h.run();
```

方法装饰器二：如何用方法装饰器修改类里面的方法

[代码示例](../../demo/lesson_10/demo4/index.ts)
```ts
function get(param: any) {
    return function(target: any, methodName: any, desc: any) {
        console.log(target);
        console.log(methodName);
        console.log(desc.value);

        /* 修改装饰器的方法，把装饰器里面传入的所有参数改为string类型 */
        /* 1.保存当前的方法 */
        let oMethod = desc.value;
        desc.value = function(...args: any[]) {

            args = args.map((value) => {
                return String(value)
            })

            console.log(args);

            /* 到此为止还只是替换原方法，需要加上下一句，才能实现修改方法的目的 */
            oMethod.apply(this, args);
        }
    }
}

class HttpClient {
    constructor() {

    }

    @get('www.baidu.com')
    getData(...args: any[]) {
        console.log(args);
        console.log('这是原方法');
    }
}

const h = new HttpClient();
h.getData(123, 'hello');
/**
 * 最后这里将会依次打印出： 
 * 1.['123', 'hello']
 * 2.['123', 'hello'] （说明装饰器在原方法之前运行）
 * 3.'这是原方法'
 */
```

## 方法参数装饰器

参数装饰器表达式会在运行时当做函数被调用，可以使用参数装饰器为类的原型增加一些元素数据，传入下列3个参数：
1. 对于静态成员来说是类的构造函数，对于实例成员是类的原型对象
2. 方法的名字
3. 参数在函数参数列表中的索引

[代码示例](../../demo/lesson_10/demo5/index.ts)
```ts
function logParam(param: any) {
    return function(target: any, methodName: any, paramIndex: any) {
        console.log(param);
        console.log(target);
        console.log(methodName);
        console.log(paramIndex);

        /* 也能给对象增加属性 */
        target.apiUrl = 'hello world';
    }
}

class HttpClient {
    public url: string | undefined;

    constructor() {

    }

    getData(@logParam('www.baidu.com') uuid: any) {
        console.log(uuid);
    }
}

const h = new HttpClient();
h.getData('123');

/** 
 * 依次打印：
 * 1.'www.baidu.com'
 * 2.[getData: Function]
 * 3.getData
 * 4.0
 * 5.'123'
 */

console.log(h.apiUrl);              // 'hello world'
```

## 装饰器的执行顺序

1. 属性装饰器(@logAttribute)
2. 方法装饰器(@logMethod)
3. 方法参数装饰器2(@logParam2)
4. 方法参数装饰器1(@logParam1)
5. 类装饰器2(@logClass2)
6. 类装饰器1(@logClass1)

属性 》 方法 》 方法参数 》 类

如果有多个同样的装饰器，他会先执行后面的

```ts
@logClass1('1')
@logClass2('2')
class HttpClient {
    @logAttribute()
    public apiUrl: string | undefined;

    constructor() {

    }

    @logMethod()
    getData() {
        return true;
    }

    setData(@logParam1('3') args1: string, @logParam2('4') args2: string) {

    }
}

const h: any = new HttpClient();

```