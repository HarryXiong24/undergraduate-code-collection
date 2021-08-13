/*
* 1.枚举成员类型
* 我们可以把枚举成员当做类型来使用
* */

enum Gender {
    male = 'woftsun',
    female ='qsc'
}
interface Interface {
    age:Gender.female;
}

// class Person implements Interface{
//     // age:Gender.female;
//     // age:Gender.male  // 类型不匹配报错
//     // age:'woftsun'    // 报错
// }

/*
* 2.联合枚举类型
*
* 联合类型就是讲多种数据类型通过|连接起来
* 我们可以把枚举类型当做一个联合类型来使用
* */

// let value:(number | string);
// value = 2;
// value = 'qsc';

enum People{
    male,
    female
}

interface Student {
    name:People   // age:(People.male | People.female)
}

class Student implements Student {
    gender:People.male;
    name:People
}


//  有点小问题 下来还要看一下