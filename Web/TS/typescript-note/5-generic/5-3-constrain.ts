{
  interface Employee {
    pay(): void;
  }

  class FullTimeEmployee implements Employee {
    pay() {
      console.log(`full time`);
    }
    workFullTime() {}
  }

  class PartTimeEmployee implements Employee {
    pay() {
      console.log(`part time`);
    }
    workPartTime() {}
  }

  // BAD!!!!
  // 세부적인 타입을 인자로 받아서 정말 추상적인 타입으로 다시 리턴하는 함수는 좋지않다
  function payBad(employee: Employee): Employee {
    employee.pay();
    return employee;
  }

  // Good with constrain
  // Generic that only extends Employee interface
  function payGood<T extends Employee>(employee: T): T {
    employee.pay();
    return employee;
  }

  const me = new FullTimeEmployee();
  const josh = new PartTimeEmployee();
  me.workFullTime();
  josh.workPartTime();

  const meAfterPay = payGood(me);
  const joshAfterPay = payGood(josh);
}

{
  function getValue<T, K extends keyof T>(obj: T, key: K): T[K] {
    return obj[key];
  }

  const obj = {
    name: 'youngjun',
    age: 29,
  };

  console.log(getValue(obj, 'name'));
  console.log(getValue(obj, 'job')); // error
}
