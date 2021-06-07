
// // 880ms 77.78% 73.4MB 77.78%
// // sort
// // O(NlgN) O(1)
// class Solution {
//     fun reductionOperations(nums: IntArray): Int {
//         nums.sort()
//         var cnt = 0
//         val n = nums.size
//         for (i in n-1 downTo 0) {
//             if (i < n-1 && nums[i] < nums[i+1]) {
//                 cnt += n-1-i
//             }
//         }        
//         return cnt
//     }
// }

// 484ms 100.00% 45.3MB 100.00%
// hash map
// O(N) O(1)
class Solution {
    fun reductionOperations(nums: IntArray): Int {
        var freq = IntArray(50001)
        nums.forEach {
            num -> freq[num]++;
        }
        val n = freq.size
        var cnt = 0
        var prv = 0
        for (num in n-1 downTo 0) {
            if (freq[num] == 0) {
                continue
            }
            cnt += prv + freq[num]
            prv += freq[num]
        }
        return cnt - prv        
    }
}
