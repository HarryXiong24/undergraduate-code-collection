## 基础类型[G01]
+ 数组[G0101]
+ 元组[G0102]
+ 枚举[G0103]
  + 便于理解的例子
  ```Typescript
  // ts文件
  enum Color {Red, Green, Blue};
  let c: Color = Color.Green;
  let d: Color = Color[2];
  if (true) console.log(c);
  if (true) console.log(d);

  // 编译后的js
  var Color;
  (function (Color) {
      console.log('Color', Color); // => {}
      // 这里的操作给对象添加了6个属性
      Color[Color["Red"] = 0] = "Red";
      Color[Color["Green"] = 1] = "Green";
      Color[Color["Blue"] = 2] = "Blue";
  })(Color || (Color = {}));

  var c = Color.Green;
  var d = Color[1];

  if (true) console.log(c); // => 1
  if (true) console.log(typeof d); // => string
  if (true) console.log(Color); // => Object {0: "Red", 1: "Green", 2: "Blue", Red: 0, Green: 1, Blue: 2}

  // 对象属性为数字会怎么样呢?
  const obj1 = {};
  obj1[1] = '1';
  obj1[2] = '2';
  console.log(obj1); // => Object {1: "1", 2: "2"}
  ```
+ 类型断言[G0104]

> 参考资料
+ [中文基本类型](https://www.tslang.cn/docs/handbook/basic-types.html)