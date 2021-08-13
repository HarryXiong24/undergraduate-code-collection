/* 枚举[G0103] */
// @desc 固定索引的对象
// @desc 访问对象的索引返回对应的
enum Color {Red, Green, Blue};
let a1 = Color.Green;
let a2 = Color[2];
if (true) console.log(a1);
if (true) console.log(a2);
