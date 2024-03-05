{
  // Interface (규격사양)
  interface StackInterface {
    readonly size: number; // can't change the value from outside
    push(value: string): void;
    pop(): void;
  }

  class Node {
    data: string | null = null;
    next: Node | null = null;
    constructor(value: string) {
      this.data = value;
      this.next = null;
    }
  }

  class Stack implements StackInterface {
    head: Node | null;
    size: number;
    constructor() {
      this.head = null;
      this.size = 0;
    }

    // push
    push(value: string) {
      const node: Node = new Node(value); // data: 'youngjun' next: null;
      let current: any = this.head;
      if (this.head === null) {
        this.head = node;
      } else {
        while (current.next !== null) {
          current = current.next;
        }
        current.next = node;
      }
      this.size++;
    }

    // pop
    pop(): void {
      if (this.size === 0) {
        console.log('Stack is empty');
        return;
      }
      let current: any = this.head;
      let index: number = 0;
      while (index < this.size - 1) {
        current = current.next;
        index++;
      }
      current.next = null;
      this.size--;
    }

    printStack() {
      let current: any = this.head;
      if (this.size === 0) {
        console.log('Stack is Empty');
      } else {
        for (let i = 0; i < this.size; i++) {
          console.log(current.data);
          current = current.next;
        }
      }
    }
  }
}
