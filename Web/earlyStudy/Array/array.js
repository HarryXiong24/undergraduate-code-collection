/**
 * 开辟一个20个空间的数组
 * 不过一般不这么写
 * 一般let arr = []
 * 之后再往里面写元素
 */
// let arr1 = new Array(20)
// arr1[0] = 1
// arr1.push(2)
// console.log(arr1)

let arr2 = []
arr2[0] = 1
console.log(arr2)

// 往最后一个或多个增加元素
arr2.push(2)
// 往开头增加一个或多个元素
arr2.unshift(0)
console.log(arr2)

// 删除最后一个
arr2.pop()
// 删除开头一个
arr2.shift()
console.log(arr2)


