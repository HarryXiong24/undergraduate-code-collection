/**
 * Type Inference
 */
let text = 'hello';
// error because of type inference
// TS automatically infer text's type is a string
text = 3;

// if parameter's type is not specified, it will consider as 'any'
function print(message) {
  console.log(message);
}

// parameter's default value is string
// TS automatically infer message's type is a string
function printDefault(message = 'hello') {
  console.log(message);
}
printDefault(2); // Error

// type of result is not specified, but parameters are number
// and return is addition so TS infer return type is a number
function add(x: number, y: number) {
  return x + y;
}
