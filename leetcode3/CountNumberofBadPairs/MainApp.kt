/* Copyright (C) 2022 by iamslash */

// Idea: math
//
// bad = total - good

// 655ms 79.63% 54.4MB 96.30%
// math
// O(N) O(N)
class Solution {
    fun countBadPairs(nums: IntArray): Long {
        val n: Int = nums.size
        val total: Long = n.toLong() * (n.toLong() - 1) / 2
        var good: Long = 0
        val diffMap = mutableMapOf<Long, Long>()
        for (i in 0 until n) {
            val diff = (i - nums[i]).toLong();
            if (diffMap.containsKey(diff)) {
                good += diffMap.get(diff)!!;
            }
            diffMap.put(diff, diffMap.getOrDefault(diff, 0) + 1L);
        }
        return total - good;
    }
}
