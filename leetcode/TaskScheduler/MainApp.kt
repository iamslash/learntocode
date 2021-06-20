// A B C A B D A B C D E 

//   tasks: A A A B B B
//       n: 1
//          A B A B A B  
//   freqs: A B
//          3 3
// maxFreq: 3
// unitLen: 3 n + 1
// unitCnt: 2 maxFrq - 1
// batchCnt: unitLen * unitCnt + task count with maxFreq

// 244ms 97.94% 39.1MB 77.32%
// linear traversal
// O(N) O(1)
import kotlin.math.*
class Solution {
    fun leastInterval(tasks: CharArray, n: Int): Int {
        val freqs = IntArray(26)
        var maxFreq = 0
        for (task in tasks) {
            freqs[task-'A']++
            maxFreq = max(maxFreq, freqs[task-'A']) 
        }
        val unitLen = n + 1
        val unitCnt = maxFreq - 1
        var batchCnt = unitLen * unitCnt
        for (freq in freqs) {
            if (freq == maxFreq) {
                batchCnt++
            }
        }
        return max(batchCnt, tasks.size)
    }
}
