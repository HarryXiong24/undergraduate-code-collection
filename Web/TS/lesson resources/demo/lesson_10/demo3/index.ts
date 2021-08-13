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