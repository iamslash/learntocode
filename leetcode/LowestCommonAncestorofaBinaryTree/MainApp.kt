/* Copyright (C) 2022 by iamslash */

class TreeNode(var `val`: Int = 0) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

// 329ms 67.49% 44.5MB 75.56%
// lca
// O(N) O(lgN)
class Solution {
    fun lowestCommonAncestor(u: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        // base
        if (u == null || u == p || u == q) {
            return u;
        }
        // recursion
        val l = lowestCommonAncestor(u.left, p, q);
        val r = lowestCommonAncestor(u.right, p, q);
        if (l != null && r != null) {
            return u;
        }
        if (l != null) {
            return l;
        }
        return r;
    }
}

fun main() {
    println("Hello World")
}
