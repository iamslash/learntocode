
// 316ms 100.00% 41.6MB 100.00%
// binary search, sliding window
// O(NlgN) O(1)
class Solution {
    fun cntLessEqual(nums: IntArray, tgtSum: Int): Int {
        var i = 0; var sum = 0; var cnt = 0
        for (j in 0 until nums.size) {
            sum += nums[j]
            while (sum > tgtSum) {
                sum -= nums[i++];
            }
            cnt += j - i + 1
        }
        return cnt
    }
    fun kthSmallestSubarraySum(nums: IntArray, k: Int): Int {
        var lo = 1; var hi = nums.sum()
        while (lo < hi) {
            val mi = lo + (hi-lo)/2
            if (cntLessEqual(nums, mi) < k) {
                lo = mi + 1
            } else {
                hi = mi
            }
        }
        return lo
    }
}
