// 去除null或undefined检测
function getLength(val) {
    return function () {
        return val.length;
    };
}
var fn = getLength('woftsun');
var res = fn();
console.log(res);
