
// 244ms 90.43% 41.2MB 35.11%
// DFS, pre-order
import java.util.*
const val SEP = ","
const val NUL = "N"
class Codec() {
    fun serialize(u: TreeNode?): String {
        val sb = StringBuilder()
        buildString(u, sb)        
        return sb.toString()
    }
    fun buildString(u: TreeNode?, sb: StringBuilder): Unit {
        // base
        if (u == null) {
            sb.append(NUL).append(SEP)
            return
        }
        // recursion
        sb.append("${u?.`val`}").append(SEP)
        buildString(u?.left, sb)
        buildString(u?.right, sb)
    }
    fun deserialize(s: String): TreeNode? {
        val nodes = LinkedList<String>(s.split(SEP))
        return buildTree(nodes)
    }
    fun buildTree(nodes: LinkedList<String>): TreeNode? {
        // base
        val  `val` = nodes.poll()        
        if (`val`.equals(NUL)) {
            return null
        }
        // recursion
        val u = TreeNode(Integer.parseInt(`val`))
        u.left = buildTree(nodes)
        u.right = buildTree(nodes)
        return u
    }
}
