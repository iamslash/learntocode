/* Copyright (C) 2022 by iamslash */

// 345ms 100.00% 41.4MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    fun checkDistances(s: String, distances: IntArray): Boolean {
        val n = s.length
        val prevIdxs = IntArray(26, { -1 })
        for (i in 0 until n) {
            val c = s.get(i)
            val idx = c - 'a'
            if (prevIdxs[idx] >= 0) {
                val dist = i - prevIdxs[idx] - 1
                if (dist != distances[idx]) {
                    return false
                }
            }
            prevIdxs[idx] = i
        }
        return true
    }
}
