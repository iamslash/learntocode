
// 140ms 88.89% 33.8MB 88.89%
// math
// O(1) O(1)
import kotlin.math.*
class Solution {    
    fun toMin(s: String): Int {
        return s.substring(0,2).toInt() * 60 +
        s.substring(3).toInt() 
    }
    fun toNextQuarterMin(numMin: Int): Int {
        return ((numMin + 14) / 15) * 15
    }
    fun toPrevQuarterMin(numMin: Int): Int {
        return (numMin / 15) * 15
    }
    fun numberOfRounds(startTime: String, endTime: String): Int {
        val startMin = toMin(startTime)
        val endMin = toMin(endTime)
        val startQuarterMin = toNextQuarterMin(startMin)
        val endQuarterMin = toPrevQuarterMin(endMin)
        if (startMin <= endMin) {
            return max(0, (endQuarterMin - startQuarterMin) / 15)
        }
        return (24*60 - startQuarterMin + endQuarterMin) / 15
    }
}
