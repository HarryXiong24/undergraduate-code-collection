/*
* Pick映射类型
* 将原有类型中的部分内容映射到新类型中
* */

interface Interface {
    name:string;
    age:number;
}
type myType = Pick<Interface, 'name'>

/*
* Record映射类型
* 他会将一个类型的所有属性值都映射到另一个类型上并创造一个新的类型
* */

type Animal = 'person' | 'cat' | 'dog';
interface Interface2 {
    name:string;
    age:number;
}

type myType2 = Record<Animal, Interface2>;
let value:myType2 = {
    person:{
        name: 'ph',
        age:30
    },
    cat:{
        name:'mm',
        age:2
    },
    dog:{
        name:'wc',
        age:3
    }
};