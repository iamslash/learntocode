// BFS
// O(N) O(N)
import kotlin.math.*
class Solution {
    fun verticalOrder(root: TreeNode?): List<List<Int>> {
        if (root == null) {
            return listOf<List<Int>>()
        }
        val q : Queue<Pair<Int, TreeNode?>> = ArrayDeque<Pair<Int, TreeNode?>>()
        val ans : MutableList<List<Int>> = mutableListOf<List<Int>>()
        val col2nodesMap = mutableMapOf<Int, MutableList<Int>>()
        var minCol = 100
        var maxCol = -100
        q.offer(Pair(0, root))
        while (q.size > 0) {
            val (col, node) = q.poll()
            minCol = min(minCol, col)
            maxCol = max(maxCol, col)
            val nodes = col2nodesMap.getOrPut(col, { mutableListOf<Int>() })
            nodes.add(node!!.`val`)
            if (node.left != null) {
                q.offer(Pair(col-1, node.left))
            }
            if (node.right != null) {
                q.offer(Pair(col+1, node.right))
            }
        }
        for (i in minCol..maxCol) {
            ans.add(col2nodesMap[i]!!.toList())
        }
        return ans.toList()
    }
}
