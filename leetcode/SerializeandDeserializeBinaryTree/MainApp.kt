// 308ms 34.04% 41.1MB 38.30%
// DFS, pre-order
// O(N) O(lgN)
class Codec() {
    fun serialize(u: TreeNode?): String {
        return when (u) {
            null -> "N"
            else -> listOf(u.`val`,
                           serialize(u.left),
                           serialize(u.right)).joinToString(",")            
        }
    }
    fun deserialize(s: String): TreeNode? {
        return deserialize(s.split(",").toMutableList())
    }
    fun deserialize(nodes: MutableList<String>): TreeNode? {
        // base
        val s = nodes.removeAt(0)
        if (s == "N") {
            return null
        }
        // recursion
        val u = TreeNode(s.toInt())
        u.left = deserialize(nodes)
        u.right = deserialize(nodes)
        return u
    }
}    
