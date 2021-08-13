/*
* 1.交叉类型
*
* 格式： type1 & type2 。。。
* 交叉类型是将多个类型合并为一个类型
* */

/*
let mergeFn = <T,U>(a:T,b:U):(T & U) => {
    let res = {} as (T & U);
    res = Object.assign(a,b);
    return res;
};

let res = mergeFn({name:'qsc'},{age:18});
console.log(res);  //  {name:'qsc',age:18}
*/


// 2.联合类型

// 就是用|连起来的  前面已经学过了