{
  // BAD
  function checkNotNullBad(arg: number | null): number {
    if (arg == null) {
      throw new Error('not valid number');
    }
    return arg;
  }
  const result = checkNotNullBad(123);
  console.log(result);
  //   checkNotNullBad(null); // Error

  // BAD!! Not type is not guaranteed
  function checkNotNullAny(arg: any | null): any {
    if (arg == null) {
      throw new Error('not valid number!');
    }
    return arg;
  }
  const result2 = checkNotNullAny(123);

  // GOOD with GENERIC
  // if user pass string, it will return string
  // if user pass number, it will return number
  function checkNotNull<T>(arg: T | null): T {
    if (arg == null) {
      throw new Error('not valid number!');
    }
    return arg;
  }

  const number = checkNotNull(123);
  const bool: boolean = checkNotNull(true);
}
