/**
 * Type Assertions 💩
 */

// assuming this is a javascript function
// TypeScript does not know its return type
// but it always returns string
function jsStringFunction(): any {
  return 'hello';
}

const result = jsStringFunction(); // TS reads this as 'any' type
result.length; // therefore it cannot use string api because the type is 'any'

// Type assertion can be used when
// I know what type is the function returning for sure
(result as string).length; // 5
(<string>result).length; //5

// If for reason the function did not return string but number
// and use the string api, it won't give error when compiling
// however it will return undefined
function jsStringFunction(): any {
  return 2;
}
const result = jsStringFunction();
(result as string).length; // undefined

// App will die in this case
const wrong: any = 5;
(wrong as Array<number>).push(1); // app dies with type error

// returns either array or undefined
function findNumbers(): number[] | undefined {
  return undefined;
}
const numbers = findNumbers();
numbers.push(2); // warning because numbers can be undefined
numbers!.push(2); // no warning, justifying this is not undefined