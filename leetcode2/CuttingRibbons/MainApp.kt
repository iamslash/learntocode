// binary search
// O(NlgN) O(1)
// 500ms 100.00% 51.3MB 50.00%
class Solution {
    fun cuttable(ribbons: IntArray, k: Int, len: Int): Boolean {
        var cnt = 0
        for (rib in ribbons) {
            cnt += (rib / len)
        }
        return cnt >= k
    }
    fun maxLength(ribbons: IntArray, k: Int): Int {
        var lo = 1
        var hi = 1e5.toInt() + 1
        while (lo < hi) {
            var mi: Int = lo + (hi - lo) / 2
            if (cuttable(ribbons, k, mi)) {
                lo = mi + 1
            } else {
                hi = mi
            }
        }
        return lo-1
    }
}
