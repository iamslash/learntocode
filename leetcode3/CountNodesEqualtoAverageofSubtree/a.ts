// Copyright (C) 2023 by iamslash

class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

// 53ms 100.00% 47.9MB 42.86%
// dfs
// O(N) O(lgN)
function averageOfSubtree(root: TreeNode | null): number {
    let best = 0;
    function dfs(u: TreeNode | null): [number, number] {
        // base
        if (u == null) {
            return [0, 0];
        }
        // recursion
        const [lsum, lcnt] = dfs(u.left)
        const [rsum, rcnt] = dfs(u.right)
        const sum = lsum + rsum + u.val
        const cnt = lcnt + rcnt + 1
        if (Math.floor(sum / cnt) === u.val) {
            best++;
        }
        return [sum, cnt]
    }
    dfs(root)
    return best
};
