{
  type Video = {
    title: string;
    author: string;
  };

  type Animal = {
    name: string;
    age: number;
  };

  // <T> any type
  // 기존에 있는 T타입을 빙글빙글 돌면서
  // T[P] P키에 해당하는 value를 타입을 선언
  type Optional<T> = {
    [P in keyof T]?: T[P]; // for...in
  };

  type ReadOnly<T> = {
    readonly [P in keyof T]: T[P];
  };

  type VideoOptional = Optional<Video>;

  const videoOptional: VideoOptional = {};
  const animal: Optional<Animal> = {};

  // T[P]를 사용하거나 null을 사용
  type Nullable<T> = {
    [P in keyof T]: T[P] | null;
  };

  const obj2: Nullable<Video> = {
    title: null,
    author: null,
  };
}
