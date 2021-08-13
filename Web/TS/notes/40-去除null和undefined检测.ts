// 去除null或undefined检测
function getLength(val:(string | null | undefined)) {
    return () => {
        return val!.length;
    }
}

let fn = getLength('woftsun');
let res = fn();
console.log(res);

// 我们可以使用！来去除null和undefined
// ！的含义就是这个变量一定不是null和undefined