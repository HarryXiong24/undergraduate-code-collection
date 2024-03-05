{
  // Array
  const fruits: string[] = ['🍎', '🥝'];
  const scores: Array<number> = [1, 3, 4];

  // if I do not want to make a function to change my original array
  // use readonly
  // readonly cannot be used on Array<number>
  function printArray(fruits: readonly string[]): void {
    //   fruits.push('banana'); // error
  }

  // Tuple: array that can hold multiple types (Not recommended)
  let student: [string, number];
  student = ['name', 123];
  student[0]; // name
  student[1]; // 123
}
