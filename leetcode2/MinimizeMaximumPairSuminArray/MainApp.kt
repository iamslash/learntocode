
import kotlin.math.*

// 736ms 86.96% 100.2MB 26.09%
// sort
// O(NlgN) O(1)
import kotlin.math.*
class Solution {
    fun minPairSum(nums: IntArray): Int {
        val n = nums.size
        var maxPair = 0
        nums.sort()
        for (i in 0 until n) {
            maxPair = max(maxPair, nums[i] + nums[n-1-i])
        }
        return maxPair
    }
}
