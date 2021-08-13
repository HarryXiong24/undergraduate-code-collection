// 额外的属性检查[G0303]=========================
interface Student {
  name?: string
  age?: number
}

function showName(Student: Student) {
  console.log(Student.name);
}

const tom1 = {name: '张三', age: 6};
showName(tom1);

// End=========================
