/* Copyright (C) 2021 by iamslash */

// 244ms 10..00% 36.3MB 100.00%
// linear traversal
// O(N) O(N)
class Solution {
    fun getConcatenation(nums: IntArray): IntArray {
        val n = nums.size
        val ans = IntArray(n*2)
        for (i in 0 until n) {
            ans[i] = nums[i]
            ans[i+n] = nums[i]
        }
        return ans
    }
}

fun main() {
    println("Hello World")
}
