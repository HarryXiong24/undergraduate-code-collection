// 定义一个接口
interface fullName {
    firstName:string
    lastName:string
    age?:number
}

// 需求：如果传递了age就输出完整信息，如果没有传递就显示部分信息

function say({firstName,lastName,age}:fullName):void {
    console.log(`嘿嘿我是${lastName}${firstName}${age}`);
}

let obj = {
    firstName:'shengcheng',
    lastName:'qi',
};

say(obj);
interface Interface {
    name:string
    age:number,
    gender:string
    [propName:string]:any
}

function demo({name, age ,gender}:Interface):void {
    console.log(`嘿嘿我是${name}${age}`);
}
demo({"name":'qsc','age':18,"gender":'man'});
