{
  /**
   * Union Types: OR
   */
  type Direction = 'left' | 'right' | 'up' | 'down';
  function move(direction: Direction) {
    console.log(direction);
  }
  //   move('hello'); // error
  move('left');

  type TileSize = 8 | 16 | 32;
  const tile: TileSize = 16; // can only define 8, 16, or 32

  /**
   * Example
   * function: login -> success, fail
   */

  type SuccessState = {
    response: {
      body: string;
    };
  };
  type FailState = {
    reason: string;
  };
  type LoginState = SuccessState | FailState;

  function login(id: string, password: string): Promise<LoginState> {
    return new Promise((resolve) => {
      resolve({
        response: {
          body: 'logged in',
        },
      });
    });
  }
}
