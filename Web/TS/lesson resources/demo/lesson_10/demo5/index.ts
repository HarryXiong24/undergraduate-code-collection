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

const h: any = new HttpClient();
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