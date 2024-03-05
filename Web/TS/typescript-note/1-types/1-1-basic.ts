{
  // javascript
  // old: var !!!! never use var 💩!!!!!
  var age = 5;

  // let
  let name = 'hello';
  name = 'hi';

  // const
  const number = 5;
  //   number = 5; // error
}

{
  /**
   * Javascript
   * Primitive: number, string, boolean, bigint, symbol, null, undefined
   * Object: function, array, etc
   */

  // number
  const num: number = 25;

  // string
  const str: string = 'hello';

  // boolean
  const bool: boolean = true;

  // undefined
  let age: number | undefined; // age can hold either number or undefined
  age = undefined;
  age = 1;
  // can either return number or undefined
  function find(): number | undefined {
    return undefined;
  }

  // null
  let person: string | null;
  person = null;
  person = 'youngjun';

  // unknown !! don't use 💩!!
  let notSure: unknown = 0;
  notSure = 'he';
  notSure = true;

  // any !! don't use 💩!!
  let anything: any = 0;
  anything = 'hello';

  // void
  // if the function does not return something, it's void
  function print(): void {
    console.log('hello');
    return;
  }

  // never
  // cannot return anything
  function throwError(message: string): never {
    // message -> server (log)
    throw new Error(message); // application stops
  }

  // object !! don't use 💩 !!
  let obj: object;
  function acceptSomeObject(obj: object) {}
  acceptSomeObject({ name: 'youngjun' });
  acceptSomeObject({ animal: 'dog' });
}
