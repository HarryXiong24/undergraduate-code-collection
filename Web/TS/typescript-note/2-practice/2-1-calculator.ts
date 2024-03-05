type Arithmetic = 'add' | 'subtract' | 'multiply' | 'divide' | 'remainder';

function calculate(arithmetic: Arithmetic, num1: number, num2: number): number {
  switch (arithmetic) {
    case 'add':
      return num1 + num2;
    case 'subtract':
      return num1 - num2;
    case 'multiply':
      return num1 * num2;
    case 'divide':
      return num1 / num2;
    case 'remainder':
      return num1 % num2;
    default:
      throw new Error('invalid');
  }
}

console.log(calculate('add', 1, 3));
console.log(calculate('subtract', 3, 1));
console.log(calculate('multiply', 4, 2));
console.log(calculate('divide', 4, 2));
console.log(calculate('remainder', 5, 2));
