// 参数添加 : string 类型注解
function greeter(person: string) {
    return `Hello, ${person}`
}
const user = 'Jane User'
const user1 = [1, 2, 3]

// 传入一个数组
// document.body.innerHTML = greeter(user1)
// 不传入参数
document.body.innerHTML = greeter()