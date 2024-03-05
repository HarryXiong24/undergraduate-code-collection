// Java: Exception
// JavaScript: Error

// const array = new Array(10000000000000000000); // RangeError: Invalid array length

// Error(Exception) Handling: try -> catch -> finally

function readFile(file: string): string {
  if (file === 'not exists') {
    throw new Error(`file not exist! ${file}`);
  }
  return 'file contents';
}

function closeFile(file: string) {
  //
}

const file = 'not exists'; // Error: file not exist! not exists

try {
  console.log(readFile(file)); // Error, but does program still runs
} catch (error) {
  console.log(`catched`);
} finally {
  // even though error occurred, finally will still be called
  closeFile(file);
  console.log('finally!!');
}
