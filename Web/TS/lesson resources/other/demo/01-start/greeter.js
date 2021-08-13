function greeter(person) {
    return "Hello, " + this.person;
}
var user = 'Jane User';
document.body.innerHTML = greeter(user);
