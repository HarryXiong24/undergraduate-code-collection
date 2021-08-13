let arr:[number, string] = [123, 'hello'];

// let arr1:Array<number,string> = [123, 'hello'];      // 报错

// let arr2:[number, string] = ['hello', 123];          // 报错

enum colors {red, blue=3, 'yellow'};
let c:colors = colors.yellow;
console.log(c);             // 4
c = colors.red;
console.log(c);             // 0