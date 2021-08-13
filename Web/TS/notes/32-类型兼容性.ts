// 基本兼容性

interface Test {
    name:string;
}
let p1 = {name:'qsc'};
let p2 = {age:18};
let p3 = {name:'qsc',age: 18};

let t:Test;

t = p1;
// t = p2;  // 报错
t = p3;

// interface Demo {
//     name:string;
//     children:{
//         age:number
//     }
// }
//
// let q1 = {name:'qsc'};
// let q2 = {name:'qsc',children:{name:'11'}};
//
// let w:Demo;
// w = q2;
// w = q1;  // 都报错 会递归检查