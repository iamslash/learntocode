/* Copyright (C) 2022 by iamslash */

// 477ms 11.78% 44.8MB 7.33%
// sort
// O(NlgN) O(1)
class Solution {
    fun findKthLargest(nums: IntArray, k: Int): Int {
        nums.sort()
        return nums[nums.size - k]
    }
}

fun main() {
    println("Hello World")
}
