// 函数类型接口: 对方法传入的参数及返回值进行约束  批量约束

// 加密的函数类型接口
interface encrypt {
  (key:string,value:string):string
}

let md5:encrypt = function(key:string, value:string):string {
  // 模拟操作
  return key + value
}

console.log(md5('名字', '张三'))
