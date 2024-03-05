{
  /**
   * Type Aliases
   */
  type Text = string; // saying Text type is now string
  const name: Text = 'youngjun';
  const address: Text = 'california';

  // number
  type Num = number;
  // object
  type Student = {
    name: string;
    age: number;
  };
  // student must have name with string and age with number
  const student: Student = {
    name: 'youngjun',
    age: 29,
  };

  /**
   * String Literal Types
   */
  type Name = 'name';
  let someName: Name;
  //   someName = 'youngjun'; // error
  type JSON = 'json';
  const json: JSON = 'json';

  type Bool = true;
  const isCat: Bool = true;
}
