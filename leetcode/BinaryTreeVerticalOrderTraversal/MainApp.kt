/* Copyright (C) 2022 by iamslash */
import java.util.*
import kotlin.math.*

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

// 431ms 6.30% 37.1MB 62.99%
// BFS
// O(N) O(N)
import kotlin.math.*
class Solution {
    fun verticalOrder(root: TreeNode?): List<List<Int>> {
        if (root == null) {
            return listOf<List<Int>>()
        }
        val q: Queue<Pair<Int, TreeNode>> = ArrayDeque<Pair<Int, TreeNode>>()
        val ans = mutableListOf<List<Int>>()
        val valsMap = mutableMapOf<Int, MutableList<Int>>()
        q.offer(Pair<Int, TreeNode>(0, root))
        var minOrder = 0
        var maxOrder = 0
        while (q.isNotEmpty()) {
            val (order, node) = q.poll()
            minOrder = min(minOrder, order)
            maxOrder = max(maxOrder, order)
            val vals = valsMap.getOrPut(order, { mutableListOf<Int>() })
            vals.add(node.`val`)
            if (node.left != null) {
                q.offer(Pair<Int, TreeNode>(order-1, node.left!!))
            }
            if (node.right != null) {
                q.offer(Pair<Int, TreeNode>(order+1, node.right!!))
            }
        }
        for (i in minOrder..maxOrder) {
            ans.add(valsMap[i]!!.toList())
        }
        return ans.toList()
    }
}

fun main() {
    println("Hello World")
}
