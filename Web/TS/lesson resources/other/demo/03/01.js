function showName(person) {
    console.log(person.name);
}
var tom = { 'name': 'Tom', age: 18 };
showName(tom);
function showAge(person) {
    console.log(person.age);
}
var jack = { name: 'Jack', age: 16 }, john = { age: 15 };
showAge(jack);
showAge(john);
