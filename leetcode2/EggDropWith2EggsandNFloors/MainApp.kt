
// 168ms 100.00% 33.5MB 100.00%
// recursive dynamic programming
// O(N) O(N)
import kotlin.math.*
class Solution {
    var C: IntArray = IntArray(1001)
    fun twoEggDrop(n: Int): Int {
        // base
        // memo
        if (C[n] > 0) {
            return C[n]
        }
        // recursion
        C[n] = n
        for (i in 1..n) {
            C[n] = min(C[n], 1 + max(i-1, twoEggDrop(n-i)))
        }
        return C[n]
    }
}
