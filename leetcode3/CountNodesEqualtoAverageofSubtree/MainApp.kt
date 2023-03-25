/* Copyright (C) 2023 by iamslash */

import java.util.*

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

// 191ms 53.85% 35.9MB 61.54%
// dfs
// O(N) O(lgN)
class Solution {
    var best: Int = 0
    fun dfs(u: TreeNode?): Pair<Int, Int> {
        // base
        if (u == null) {
            return 0 to 0
        }
        // recursion
        val lrst = dfs(u.left)
        val rrst = dfs(u.right)
        val sum = lrst.first + rrst.first + u.`val`
        val cnt = lrst.second + rrst.second + 1
        if (sum / cnt == u.`val`) {
            best += 1
        }
        return sum to cnt
    }
    fun averageOfSubtree(root: TreeNode?): Int {
        dfs(root)
        return best
    }
}

fun main() {
    println("Hello World")
}
