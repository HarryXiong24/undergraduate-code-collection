// 1.什么是索引签名
// 索引签名用于描述那些"通过索引得到"的类型  比如  arr[10]或者obj[key]

interface fullName {
    [propName:string]:string
}

let obj:fullName = {
    //  注意点： 只要key和value满足索引签名的限定即可，无论有多少个都无所谓
    firstName:"woftsun",
    lastName:'qi',
    age: '18'
};



// 2.只读属性
// 让对象属性只能在对象刚刚创建的时候修改其值

interface Interface {
    firstName:string
    readonly lastName:string
}

let obj1:Interface = {
    firstName:'woftsun',
    lastName:'qi'
};

console.log(obj1);


// ts根据只读属性进行了扩展，扩展出来了一个只读数组

let arr2 :ReadonlyArray<string> = ['a','b','c'];
// arr2[1] = 123;  // 这个地方已经不能改了

