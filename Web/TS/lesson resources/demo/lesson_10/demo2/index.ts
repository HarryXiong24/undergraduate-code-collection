function logClass(target: any) {
    return class extends target {
        apiUrl:string = '修改后的str';

        getData() {
            this.apiUrl = '123';
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
console.log(h.apiUrl);
console.log(h.getData());