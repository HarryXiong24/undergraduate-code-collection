/*
* 1.什么是自动类型推断
* 不用明确告诉编译器具体是什么类型，编译器就知道是什么类型
* */

// 1.根据初始化的值自动推断

// 如果是先定义在初始化，那么是无法自动推断的
// let value;
// value = 123;
// value = 'qsc';
// value = false;

// 如果是定义的同时初始化，那么ts就会自动进行类型推断
// let value = 123;   //  等价于 let value:number = 123;
// value = 456;
// value = 'qsc';  // 报错

let arr = [123,'123']; // 等价于 let arr(number|string) = [123,'123'];
// arr = [123,false]  // 报错

// 2.根据上下文类型自动推断
window.onmousedown = (e) => {
    console.log(e.target);
};