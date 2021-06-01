import kotlin.math

// 724ms 20.00% 56.8MB 20.00%
// sort
// O(NlgN) O(1)
class Solution {
    fun minProductSum(nums1: IntArray, nums2: IntArray): Int {
        nums1.sort()
        nums2.sortDescending()
        var sum = 0
        for (i in 0 until nums1.size) {
            sum += nums1[i] * nums2[i]
        }
        return sum
    }
}

// two pointers, hash map
// O(N) O(1)
class Solution {
    fun minProductSum(nums1: IntArray, nums2: IntArray): Int {
        var cnts1 = IntArray(101)
        var cnts2 = IntArray(101)
        nums1.forEach({ cnts1[it]++ })
        nums2.forEach({ cnts2[it]++ })
        var sum = 0; var i = 0; var j = 100
        while (i < 100 && j >= 0) {
            if (cnts1[i] == 0) {
                i++;
            } else if (cnts2[j] == 0) {
                j--;
            } else {
                minCnt = min(cnts1[i], cnts2[j])              
                cnts1[i] -= minCnt
                cnts2[j] -= minCnt
                sum += i * j * minCnt
            }
        }
        return sum
    }
}
