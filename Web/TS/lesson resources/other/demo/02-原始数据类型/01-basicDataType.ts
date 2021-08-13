// 数字
const a: number = 123;

// 字符串
const b: string = 'hello';

// 布尔值
const c: boolean = true;

// null （只能被赋值为null）
const d: null = null

// undefined （只能被赋值为undefined）
const e: undefined = undefined

// null undefined是所有类型的子类型,可以赋值给其他类型
const f: number = undefined
const g: string = null
// 这样也不会报错
// const h 会报错 
let h: undefined; 
const i: number = h;

// void类型的变量不能赋值给其他类型的变量
// 报错
let j: void;
const k: number = j;
const k1: string = j;
const k2: boolean = j;
