interface ConfigFn {
    <T> (value1: T): T;
}
const setData:ConfigFn = function<T> (value: T): T {
    return value;
}

console.log(setData<string>('hello'));          // 'hello'
console.log(setData<number>(123));              // 123