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