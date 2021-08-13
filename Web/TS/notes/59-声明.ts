/*
* 1.什么是声明？
* 在企业开发中我们不可避免的需要引用第三方的js库
* 但是默认情况下ts是不认识我们引入的这些js库的
* 所以在使用这些js库的时候，我们就要告诉ts它是什么，它怎么用
* 2.如何告诉ts呢
* 那就是通过什么来告诉
* */

declare const $:(selector:string) => {
    width():number;
    height():number;
    ajax(url:string,config:{}):void;
};

console.log($);