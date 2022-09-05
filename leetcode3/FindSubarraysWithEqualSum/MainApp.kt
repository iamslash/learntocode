/* Copyright (C) 2022 by iamslash */

// 291ms 34.29% 36.9MB 22.86%
// sliding window, set
// O(N) O(N)
class Solution {
    fun findSubarrays(nums: IntArray): Boolean {
        val sumSet = mutableSetOf<Int>()
        for (i in 1 until nums.size) {
            val sum = nums[i-1] + nums[i]
            if (sumSet.contains(sum)) {
                return true
            }
            sumSet.add(sum)
        }
        return false
    }
}
