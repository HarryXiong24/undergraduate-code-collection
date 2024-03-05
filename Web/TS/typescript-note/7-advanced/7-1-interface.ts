type PositionType = {
  x: number;
  y: number;
};
interface PositionInterface {
  x: number;
  y: number;
}

// object⭐️
// both type and object can assign object
const obj1: PositionType = {
  x: 1,
  y: 1,
};
const obj2: PositionInterface = {
  x: 1,
  y: 1,
  z: 1,
};

// class⭐️
class Pos1 implements PositionType {
  x: number;
  y: number;
  z: number;
}
class Pos2 implements PositionInterface {
  x: number;
  y: number;
  z: number;
}

// Extends⭐️
type ZPositionType = PositionType & { z: number };
interface ZPositionInterface extends PositionInterface {
  z: number;
}

// Only interface can be merged
interface PositionInterface {
  z: number;
}

// Only type aliases can use computed properties
type Person = {
  name: string;
  age: number;
};
type Name = Person['name']; // string type
type NumberType = number;
type Direction = 'left' | 'right';
