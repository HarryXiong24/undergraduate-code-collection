"use strict";
// function setData<T> (value: T): T {
//     return value;
// }
// const mySetData:ConfigFn<number> = setData;
var mySetData = function (value) {
    return value;
};
console.log(mySetData('20')); // 20
