// 176ms 100.00% 36MB 100.00%
// linear traversal
// O(N^2) O(N)
class Solution {
    fun removeOccurrences(s: String, part: String): String {
        var prv: String
        var cur = s
        do {
            prv = cur
            cur = cur.replaceFirst(part, "")
        } while (!cur.equals(prv));
        return cur
    }
}
