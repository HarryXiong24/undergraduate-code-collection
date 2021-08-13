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

function fun(x:never):never {
    throw new Error('不完整' + x);
}

function aera(s:Shape):number {
    switch (s.kind) {
        case "square":return s.size * s.size;
        case "rectangle":return s.width * s.height;
        case "circle":return Math.PI * s.radius ** 2; // ** 是es7中推出的幂运算符
        default: return fun(s);
    }
}