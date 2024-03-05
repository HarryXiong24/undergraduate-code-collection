function increasingBST(root: TreeNode | null): TreeNode | null {
    // let's do morris traversal
    let cur = root;
    let prevRoot = new TreeNode(0);
    let prev = prevRoot;

    while (cur !== null) {
        if (cur.left !== null) {
            const left = cur.left;
            cur.left = null; // prune

            let rightmost = left;
            while (rightmost.right !== null) rightmost = rightmost.right;
            rightmost.right = cur;

            cur = left;
        } else {
            prev.right = cur;
            prev = prev.right;
            cur = cur.right;
        }
    }

    return prevRoot.right;
}
