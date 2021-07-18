/* Copyright (C) 2021 by iamslash */

// 0: x     0
// 1: . x   2
// 2: . . x 3
//        i

// 0:       0
// 1: .     1
// 2: . . x 3
//      i

// 484ms 100.00% 55.3MB 85.71%
// sort
// O(NlgN) O(1)
class Solution {
    fun eliminateMaximum(dist: IntArray, speed: IntArray): Int {
        for (i in 0 until dist.size) {
            dist[i] = (dist[i] - 1) / speed[i]
        }
        dist.sort()
        for (i in 0 until dist.size) {
            if (i > dist[i]) {
                return i
            }
        }
        return dist.size
    }
}

fun main() {
    println("Hello World")
}
