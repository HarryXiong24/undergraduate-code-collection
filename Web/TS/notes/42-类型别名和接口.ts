// 接口和类型别名异同
// 1。都可以描述属性或者方法

// type myType = {
//     name:string;
//     say():void;
// }
//
// interface Interface {
//     name:string;
//     say():void;
// }

// 2.都允许扩展

interface myInterface {
    name:string;
    say():void;
}

interface myInterface2 extends myInterface{
    age:number;
}

let val:myInterface2 = {
    name:'qsc',
    age:18,
    say(): void {
        console.log(1);
    }
};

// type myType = {
//     name:string;
//     say():void;
// }
//
// type myType2 = myType & {
//     age:number;
// }
//
// let value:myType2 = {
//     name:'qsc',
//     age:18,
//     say(): void {
//         console.log(1);
//     }
// };

// 3.type可以声明基本类型别名，联合类型，元祖类型，interface不能

// type myType = boolean;
// type myType2 = (string | number);
// type myType3 = [string,number,boolean];

// 4.type不会自动合并
// type myType = {
//     name:string;
// }
// type myType = {
//     age:number
// }                             //  同名会报错
