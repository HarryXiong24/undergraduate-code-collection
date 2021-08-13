/**
 * TS中的数组使用[G0101]
 */

 // 方式1: 可以在元素类型后面接上 []
 let list1: number[] = [1, 2, 3];
 let list2: string[] = ['1', '2', '3'];

//  方式2: 数组泛型，Array<元素类型>
let list3: Array<number> = [1, 2, 3];
let list4: Array<string> = ['1', '2', '3'];

