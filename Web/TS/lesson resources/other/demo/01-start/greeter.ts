function greeter(person) {
    return `Hello, ${this.person}`
}
const user = 'Jane User'

document.body.innerHTML = greeter(user)