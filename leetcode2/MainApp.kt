/* Copyright (C) 2021 by iamslash */

// 480ms 81.82% 41.3MB 81.82%
// hash map
// O(N) O(1)
import kotlin.math.*
class Solution {
    fun countPalindromicSubsequence(s: String): Int {
        val firstIdxs = IntArray(26) { Int.MAX_VALUE }
        val lastIdxs = IntArray(26) 
        val n = s.length
        var cnt = 0
        for (i in 0 until n) {
            val charIdx = s[i] - 'a'
            firstIdxs[charIdx] = min(firstIdxs[charIdx], i)
            lastIdxs[charIdx] = i
        }
        for (i in 0 until 26) {
            if (firstIdxs[i] < lastIdxs[i]) {
                cnt += s.substring(firstIdxs[i]+1, lastIdxs[i])
                    .toCharArray()
                    .distinct()
                    .size
            }
        }
        return cnt
    }
}

fun main() {
    println("Hello World")
}
