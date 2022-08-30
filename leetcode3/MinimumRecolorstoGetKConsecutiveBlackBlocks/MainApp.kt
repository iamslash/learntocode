/* Copyright (C) 2022 by iamslash */


// 284ms 6.98% 34.2MB 41.86%
// sliding window
// O(N) O(1)
import kotlin.math.*
class Solution {
    fun minimumRecolors(blocks: String, k: Int): Int {
        val n: Int = blocks.length
        var whiteCnt: Int = 0
        var minWhiteCnt: Int = k
        for (i in 0..n-1) {
            val c = blocks.get(i)
            whiteCnt += if (c == 'W') 1 else 0
            if (i >= k) {
                whiteCnt -= if (blocks.get(i - k) == 'W') 1 else 0
            }
            if (i >= k - 1) {
                minWhiteCnt = min(minWhiteCnt, whiteCnt)
            }
        }
        return minWhiteCnt
    }
}
