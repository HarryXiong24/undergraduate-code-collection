// 1.什么是索引签名
// 索引签名用于描述那些"通过索引得到"的类型  比如  arr[10]或者obj[key]
var obj = {
    //  注意点： 只要key和value满足索引签名的限定即可，无论有多少个都无所谓
    firstName: "woftsun",
    lastName: 'qi',
    age: '18'
};
var obj1 = {
    firstName: 'woftsun',
    lastName: 'qi'
};
console.log(obj1);
