/*
* 1.什么是可辨识联合
* 具有共同的可辨识特征
* 一个类型别名，包含了具有共同的可辨识特征的类型的联合
* */

interface Square {
    kind:'square';  // 共同的可辨识特征
    size:number;
}
interface Rectangle {
    kind:'rectangle';  // 共同的可辨识特征
    width:number;
    height:number;
}
interface Circle {
    kind:'circle';  // 共同的可辨识特征
    radius:number;
}


type Shape = (Square | Rectangle | Circle);

function aera(s:Shape) {
    switch (s.kind) {
        case "square":return s.size * s.size;
        case "rectangle":return s.width * s.height;
        case "circle":return Math.PI * s.radius ** 2; // ** 是es7中推出的幂运算符
    }
}