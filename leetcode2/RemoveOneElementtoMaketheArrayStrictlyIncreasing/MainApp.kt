
//       i
// nums: 2 3 1 2
//            . *

// 180ms 100.00% 35.9MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
    fun canBeIncreasing(nums: IntArray): Boolean {
        var removeCnt = 0
        for (i in 1 until nums.size) {
            if (nums[i-1] >= nums[i]) {
                if (removeCnt > 0) {
                    return false
                }
                removeCnt++
                if (i > 1 && nums[i-2] >= nums[i]) {
                    nums[i] = nums[i-1]
                }
            }
        }
        return true
    }
}
