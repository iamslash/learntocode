/* Copyright (C) 2022 by iamslash */

// 321ms 79.01% 47MB 58.01%
// two pointers, sort
// O(NlgN) O(N)
class Solution {
    fun minMeetingRooms(intervals: Array<IntArray>): Int {
        var n = intervals.size
        var ans = 0
        val begs = IntArray(n)
        val ends = IntArray(n)
        for (i in 0 until n) {
            begs[i] = intervals[i][0]
            ends[i] = intervals[i][1]
        }
        begs.sort()
        ends.sort()
        var j = 0
        for (i in 0 until n) {
            if (begs[i] < ends[j]) {
                ans++
            } else {
                j++
            }
        }
        return ans
    }
}

fun main() {
    val begs = intArrayOf(5, 4, 3, 2, 1)
    val ends = mutableListOf(5, 4, 3, 2, 1)
    begs.sort()
    ends.sort()
    for (a in begs) {
        print("${a} ")
    }
    for (a in ends) {
        print("${a} ")
    }
    println()
}
