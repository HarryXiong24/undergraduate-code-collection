type Directions = 'up' | 'down' | 'left' | 'right';

const position = {
  x: 0,
  y: 0,
};

function move(direction: Directions): void {
  switch (direction) {
    case 'up':
      position.y += 1;
      console.log('moved up');
      break;
    case 'down':
      position.y -= 1;
      console.log('moved down');
      break;
    case 'left':
      position.x -= 1;
      console.log('moved left');
      break;
    case 'right':
      position.x += 1;
      console.log('moved right');
      break;
    default:
      throw new Error('invalid direction');
  }
}

console.log(position);
move('up');
console.log(position);
move('down');
console.log(position);
move('left');
console.log(position);
move('right');
console.log(position);
