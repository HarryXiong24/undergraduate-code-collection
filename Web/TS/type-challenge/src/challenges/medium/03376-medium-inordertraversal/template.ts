interface TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
}

type InorderTraversal<
  T extends TreeNode | null,
  NT extends TreeNode = NonNullable<T>
> = [T] extends [null]
  ? []
  : [
      ...InorderTraversal<NT["left"]>,
      NT["val"],
      ...InorderTraversal<NT["right"]>
    ];
