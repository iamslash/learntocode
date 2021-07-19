/* Copyright (C) 2021 by iamslash */

// 436ms 78.95% 52.8MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
    fun addRungs(rungs: IntArray, dist: Int): Int {
        var prev = 0
        var ans = 0
        for (rung in rungs) {
            ans += (rung - prev - 1) / dist
            prev = rung
        }
        return ans
    }
}

fun main() {
    println("Hello World")
}
