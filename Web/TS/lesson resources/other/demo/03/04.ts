/* 函数类型[G0304]=========================
 * 接口描述一个函数
 */
interface SearchFunc {
  (source: string, subsString: string): boolean
}


let mySearch: SearchFunc;
/**
 * mySearch
 * @param {string} source
 * @param {subString} string
 * @return {boolean}
 * @desc 实参完全匹配的函数 
 */
mySearch = (source: string, subString: string) => {
  const result = source.search(subString);
  return result > -1;
}

let mySearch2: SearchFunc;
/**
 * mySearch2
 * @param {string} src
 * @param {string} sub
 * @return {boolean}
 * @desc 函数类型的类型检查来说， 函数的参数名不需要与接口里定义的
 *       名字相匹配。
 */
mySearch2 = (src: string, sub: string) => {
  const result = src.search(sub);
  return result > -1;
}

let mySearch3: SearchFunc;

/**
 * mySearch3
 * @param {string} src
 * @param {string} sub
 * @return {boolean} 
 * @desc 如果你不想指定类型，TypeScript的类型系统会推断出参数类型，
 *       因为函数直接赋值给了 SearchFunc类型变量。函数的返回值类型
 *       是通过其返回值推断出来的（此例是 false和true）
 */
mySearch3 = (src, sub) => {
  const result = src.search(sub);
  return result > -1;
}
/* End]========================= */