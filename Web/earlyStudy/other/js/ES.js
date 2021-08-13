class Person{
    constructor(name, age){
        this.name = name;
        this.age = age;
    }

    showName(){
        console.log(this.name);
    }
}

class Employee extends Person{
    constructor(name, age, salary){
        super(name, age);
        this.salary = salary;
    }

    showName(){
        console.log(this.name);
        console.log(this.salary);
    }
}

var employee = new Employee("harry", 18, 3000000);
employee.showName();