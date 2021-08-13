// 数组类型
// 方式一
// 需求：要求定义一个数组，这个数组中只能存储数值类型的数据

let arr:Array<number>;
arr = [1,2,3,45];
console.log(arr);

// 方式二
// 需求：要求定义一个数组，这个数组将来只能存储字符串类型的数据

let arr1:string[];
arr1 = ['a','b','c','d'];
console.log(arr1);

// 联合类型
let arr2:(number|string)[];  // 表示定义了一个数组，这个数组将来既可以存储字符串也可以存储数值类型的数据；
arr2 = [1,'a',34,'sd',4];
console.log(arr2);

// 任意类型
let arr3:any[];
arr3 = [1,'a',false];  // 表示将来这个数组可以存储任意类型的数据
console.log(arr3);


// 元祖类型
//ts中元祖类型其实就是数组类型的扩展
//元祖用于保存定长定数数据类型的数据

let arr4:[string, number ,boolean];
// arr4 = [1,'a',false,2]; // 超过固定长度或者是类型不对应就会报错
arr4 = ['a',2,false];
console.log(arr4);
