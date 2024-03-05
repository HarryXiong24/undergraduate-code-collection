type Merge<F extends {}, S extends {}> = {
  [P in keyof (F & S)]: P extends keyof S ? S[P] : (F & S)[P];
};
