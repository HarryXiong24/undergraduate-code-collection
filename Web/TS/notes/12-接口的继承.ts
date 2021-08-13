// 接口的继承
// ts中的接口和js中的类一样是继承的

interface length {
    length:number
}
interface width {
    width:number
}
interface height {
    height:number
}
interface rect extends length,width,height{
    color:string
}

let arr:rect = {
    length:10,
    width:20,
    height:5,
    color:'yellow'
};
console.log(arr);