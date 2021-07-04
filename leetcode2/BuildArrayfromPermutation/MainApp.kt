
// 220ms 100.00% 36.3MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    fun buildArray(nums: IntArray): IntArray {
        val n = nums.size
        val ans = IntArray(n)
        for (i in 0 until n) {
            ans[i] = nums[nums[i]]
        }
        return ans
    }
}
