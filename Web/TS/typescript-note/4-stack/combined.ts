{
  // Interface (규격사양)
  interface Stack {
    readonly size: number; // can't change the value from outside
    push(value: string): void;
    pop(): void;
  }

  type Node = {
    readonly value: string;
    next: Node | null;
  };

  class StackImpl implements Stack {
    private _size: number;
    private head: Node | null;
    get size() {
      return this._size;
    }

    constructor() {
      this.head = null;
      this._size = 0;
    }

    push(value: string): void {
      const node: Node = { value, next: null };
      if (this.head == null) {
        this.head = node;
      } else {
        let current: Node = this.head;
        while (current.next !== null) {
          current = current.next;
        }
        current.next = node;
      }
      this._size++;
    }

    pop(): void {
      if (this._size === 0) {
        console.log('Stack is empty');
        return;
      }
      let current: Node | null = this.head;
      let previous: Node | null;
      while (current.next !== null) {
        previous = current;
        current = current.next;
      }
      current!.next = null;
      this._size--;
    }

    printStack(): void {
      if (this._size === 0) {
        console.log('Stack is empty');
      } else {
        let current: Node | null = this.head;
        let index: number = 0;
        while (index < this._size) {
          console.log(current!.value);
          current = current!.next;
          index++;
        }
      }
      console.log(`Size of the stack is ${this._size}`);
    }
  }

  const stack = new StackImpl();
  stack.push('youngjun');
  stack.push('ellie');
  stack.push('josh');
  stack.printStack();
  console.log('-----------');
  stack.pop();
  stack.pop();
  stack.printStack();
}
