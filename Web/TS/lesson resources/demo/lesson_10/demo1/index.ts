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