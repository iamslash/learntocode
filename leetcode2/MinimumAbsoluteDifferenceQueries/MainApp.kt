/* Copyright (C) 2021 by iamslash */

// 2636ms 8.33% 182.8MB 33.33%
// linear traversal
// O(N) O(N)
import kotlin.math.*
class Solution {
    fun minDifference(nums: IntArray, queries: Array<IntArray>): IntArray {
        val n = nums.size
        val m = queries.size
        val ans = IntArray(m)
        val psCnt = Array(100001, { IntArray(101, { 0 }) })
        for (i in 0 until n) {
            for (a in 1 until 101) {
                psCnt[i+1][a] = psCnt[i][a] + if (a == nums[i]) 1 else 0
            }
        }
        for (i in 0 until m) {
            val fr = queries[i][0]
            val to = queries[i][1]
            var prev = 0
            var delta = Int.MAX_VALUE
            for (a in 1 until 101) {
                if (psCnt[to+1][a] - psCnt[fr][a] > 0) {
                    delta = min(delta, if (prev == 0) Int.MAX_VALUE else (a - prev))
                    prev = a
                }
            }
            ans[i] = if (delta == Int.MAX_VALUE) -1 else delta
        }
        return ans
    }
}

fun main() {
    println("Hello World")
}
