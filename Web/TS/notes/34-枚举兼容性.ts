// 数字枚举与数值兼容

enum Gender{
    male,
    female
}

let val:Gender;
val = 1;


// 数字枚举与数字枚举不兼容

enum Demo {
    male,
    female
}
enum Test {
    male,
    female
}

let res:Demo;
res = Demo.female;
// res = Test.female;  // 报错


// 字符串枚举与字符串部件用

enum People{
    male = 'qsc',
    female = 'woftsun'
}

let data:People;
data = People.male;
// data = '123'; // 报错
