/* 接口初探[G0301] */

// 适用场景
function showName(person: {name: string}) {
  console.log(person.name);
}
const tom = {'name': 'Tom', age: 18};
showName(tom);

// 接口方式
// 接口只需要定义不需要实现功能
// xxx?表示是可选的接口
interface ageValue {
  name?: string
  age: number
}
function showAge(person: ageValue) {
  console.log(person.age);
}
const jack = {name: 'Jack', age: 16},
      john = {age: 15};
      
showAge(jack);
showAge(john);