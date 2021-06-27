// 236ms 100.00% 38MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
    fun maxProductDifference(nums: IntArray): Int {
        var max1 = 0
        var max2 = 0
        var min1 = Int.MAX_VALUE
        var min2 = Int.MAX_VALUE
        for (num in nums) {
            if (num > max1) {
                max2 = max1
                max1 = num
            } else if (num > max2) {
                max2 = num
            }
            if (num < min1) {
                min2 = min1
                min1 = num
            } else if (num < min2) {
                min2 = num
            }
        }
        return max1 * max2 - min1 * min2
    }
}
