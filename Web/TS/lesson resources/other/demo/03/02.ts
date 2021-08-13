// 只读[G0302]
// 接口只读使用=========================
interface Student {
  name: string;
  age: number;
  school: string
}

const Tom: Student = {
  name: 'Tom',
  age: 18,
  school: '清华'
}

// 尝试改变只读的属性
// 报错
// Tom.age = 16;

// 没设置只读的属性可以修改
Tom.school = '北大';
// End=========================

// 数组可以全部设为只读=========================
const arr1: number[] = [1, 2, 3, 4],
      arr2: ReadonlyArray<number> = arr1;

// 可以修改
arr1[0] = 11;

// 报错：因为是只读的
// arr2[0] = 11;

// 报错: 这样也不行
// arr2.push(1);

// 赋值: 浅拷贝
const arr3 = arr2;

// 报错: arr3也是只读的
// arr3.push();
// arr3[0] = 66;

// 深拷贝
const arr4 = arr2.slice();

arr4.push(66);
arr4[0] = 111;
// 显示修改后的结果
if (!true) console.log(arr4); 

// 使用类型断言重写
// 上面的报错依然存在
// 但是arr5可以改变了
const arr5 = arr2 as number[];
arr5.push(555);
if (!true) console.log(arr5);

// 报错:只读的数组依旧报错
// arr2.push(666);
// End=========================

