interface ConfigFn<T> {
    (value1: T): T;
}

// function setData<T> (value: T): T {
//     return value;
// }
// const mySetData:ConfigFn<number> = setData;

const mySetData:ConfigFn<string> = function<T> (value: T): T {
    return value;
}

console.log(mySetData('20'));             // 20