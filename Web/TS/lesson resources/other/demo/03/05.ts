/** 
 * 可索引的类型[G0305]=========================
 * @desc 通过接口描述属性，通过索引得到的类型
 */

let line = '代码分割';
/**
 * 接口: 每项为字符串的数组
 * @desc 索引(属性)为数字类型
 * @desc 属性的值为字符串类型 
 */
interface StringArray {
  [index: number]: string;
}

let myArray: StringArray;
myArray = ['Tom2', 'Jack'];

let tom2 = myArray[0];
// or
let tom3: string = myArray[0];

// 不能这样使用，因为每项必须为字符串
// let myArray2: StringArray;
// myArray2 = [1, 2]

/**
 * 接口: 每项为数字的数组 
 */
interface NumberArray {
  [index: number]: number;
}

let myArray3: NumberArray = [1, 2, 3, 4];

/**
 * 接口: 每项为字符串的对象 
 */
interface StringObj {
  [index: string]: string;
}

/**
 * 接口: 每项为数字的对象 
 */
interface NumberObj {
  [index: string]: number
}

/**
 * 接口： 每项为布尔值的对象 
 */
interface BooleanObj {
  [index: string]: boolean
}

/**
 * 接口: 每项为任意类型的的对象 
 */
interface AnyObj {
  [index: string]: any
}
let myObj1: StringObj = {
  name: 'Tom',
  // age: 4 // 不行
  weight: '175cm'
}
let myObj2: AnyObj = {
  name: 'Jack',
  age: 18,
  isYong: true,
  weight: '180cm'
}

/**
 * 字典模式dictionary模式
 */
interface NumberDictionary {
  [index: string]: number
  length: number
  name: number
}
const numberDictionary1: NumberDictionary = {
  age1: 6,
  age2: 12,
  age3: 24,
  age4: 30, 
  length: 4,
  name: 100
}
// 这里的值是可读并可写的
numberDictionary1.age1 = 1;
if (true) console.log(numberDictionary1.age1);

interface StringDictionary {
  [index: string]: string
  length: string
  name: string
}

/**
 * 接口: 只读的索引签名(属性)
 */
interface ReadonlyAnyArray {
  readonly [index: number]: any
}
const readonlyStringArray1: ReadonlyAnyArray = [1, '2', true, '3'];
// 可读
readonlyStringArray1[1]
// 不可写
// readonlyStringArray1[1] = false;

/**
 * 接口: 实现接口
 * @desc 与C#或Java里接口的基本作用一样，TypeScript也能够用
 *       它来明确的强制一个类去符合某种契约。
 */
interface ClockInterface {
  currentTime?: Date
}

// 类使用某个接口通过关键字'implements'
// 使用了某个接口,必须要实现,即使接口设为了可选也必须实现
class Clock implements ClockInterface {
  currentTime: Date
  constructor(h: number, m: number) {}
}

/**
 * 接口中描述一个方法，在类里实现它
 * @desc 这里定义了一个方法setTime,其参数必须为Date类型
 */
interface ClockInterface2 {
  currentTime: Date
  setTime(d: Date)
}
class Clock2 implements ClockInterface2 {
  currentTime: Date
  // pass
  // setTime(d: Date) {}

  // pass
  // setTime(mD: Date) {}

  // error
  // setTime(d: string) {}

  // pass
  // why
  // setTime(d: any) {}

  // pass
  // setTime(mD: any) {}

  // pass
  // setTime(mD) {}

  // pass
  // setTime() {}

  // pass
  setTime() {}
}

/* End]========================= */