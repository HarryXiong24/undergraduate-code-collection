{
  // to access to object values
  const obj = {
    name: 'youngjun',
  };
  obj.name; // youngjun
  obj['name']; // youngjun

  type Animal = {
    name: string;
    age: number;
    gender: 'male' | 'female';
  };

  type Name = Animal['name']; // type of Name: string
  const text: Name = 'hello'; // only string possible

  type Gender = Animal['gender']; // type of Gender: 'male' | 'female'
  const gender1: Gender = 'male';
  const gender2: Gender = 'female';

  type Keys = keyof Animal; // type of Keys: 'name' | 'age' | 'gender'
  const key1: Keys = 'name';
  const key2: Keys = 'age';
  const key3: Keys = 'gender';

  type Person = {
    name: string;
    gender: Animal['gender'];
  };
  const person: Person = {
    name: 'youngjun',
    gender: 'male',
  };
}
