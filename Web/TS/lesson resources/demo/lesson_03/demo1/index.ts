function getInfo(name: string): string;

function getInfo(age: number): string;

function getInfo(str: any): string {
    let txt = '';
    if (typeof str === 'string') {
        txt = '姓名：' + str;
    } else if (typeof str === 'number') {
        txt = '年龄：' + str;
    }
    return txt;
}

console.log(getInfo('hello'));
console.log(getInfo(20));
// console.log(getInfo(true));
