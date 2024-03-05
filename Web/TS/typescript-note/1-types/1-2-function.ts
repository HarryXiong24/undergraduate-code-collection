{
  // JavaScript 💩
  function jsAdd(num1, num2) {
    return num1 + num2;
  }

  // TypeScript
  function add(num1: number, num2: number): number {
    return num1 + num2;
  }

  // JavaScript
  function jsFetchNum(id) {
    // code...
    // code...
    return new Promise((resolve, reject) => {
      resolve(100);
    });
  }

  // TypeScript
  function fetchNum(id: string): Promise<number> {
    // code...
    // code...
    return new Promise((resolve, reject) => {
      resolve(100);
    });
  }

  // ✨JavaScript => TypeScript✨
  // Optional Parameter
  // if add ?, I can pass lastName or not
  function printName(firstName: string, lastName?: string): void {
    console.log(firstName);
    console.log(lastName);
  }

  printName('youngjun', 'woo');
  //   printName('youngjun'); // error

  // Default parameter
  function printMessage(message: string = 'default message'): void {
    console.log(message);
  }

  // Rest parameter
  function addNumbers(...numbers: number[]): number {
    return numbers.reduce((a, b) => {
      return a + b;
    });
  }
}
