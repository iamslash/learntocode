/* Copyright (C) 2021 by iamslash */

//              i
// begs:  0  5 15
// ends: 10 20 30
//        j
//  ans:  2

// 301ms 25.00% 42.5MB 23.81%
// sort
// O(NlgN) O(N)
class Solution {
    fun minMeetingRooms(intervals: Array<IntArray>): Int {
        val n : Int = intervals.size
        val begs : IntArray = IntArray(n)
        val ends : IntArray = IntArray(n)
        var maxRoomCnt : Int = 0
        var i : Int = 0; var j : Int = 0
        for (k in 0 until n) {
            begs[k] = intervals[k][0]
            ends[k] = intervals[k][1]            
        }
        begs.sort()
        ends.sort()
        while (i < n) {
            if (begs[i] < ends[j]) {
                ++maxRoomCnt
            } else {
                ++j
            }
            ++i
        }
        return maxRoomCnt
    }
}

fun main() {
    println("Hello World")
}
