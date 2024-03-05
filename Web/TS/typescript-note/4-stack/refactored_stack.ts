{
  // Interface (규격사양)
  interface Stack {
    readonly size: number; // can't change the value from outside
    push(value: string): void;
    pop(): void;
  }

  // 사용자가 data를 넣어서 한단계 감싸는 무언가를 만들때는
  // 불변성을 유지하는게 좋다
  // 한번  만들어지면 절대 변경되지 않도록 readonly 사용
  type Node = {
    readonly value: string;
    readonly next?: Node;
  };

  class StackImpl implements Stack {
    private _size: number = 0;
    private head?: Node;
    get size() {
      return this._size;
    }
    
    push(value: string): void {
      const node: Node = { value, next: this.head };
      this.head = node;
      this._size++;
    }

    pop(): void {
      if (this.head == null) {
        throw new Error('stack is empty');
      }
      const node = this.head;
      this.head = node.next;
      this._size--;
    }
  }
}
