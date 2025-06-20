/* Copyright (C) 2025 by iamslash */

// 3ms 87.50% 41.92MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    fun maxFreqSum(s: String): Int {
        var maxVowelCnt = 0
        var maxConsonantCnt = 0
        val charCnts = IntArray(26)

        for (c in s) {
            val idx = c - 'a'
            charCnts[idx]++

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                if (charCnts[idx] > maxVowelCnt) {
                    maxVowelCnt = charCnts[idx]
                }
            } else {
                if (charCnts[idx] > maxConsonantCnt) {
                    maxConsonantCnt = charCnts[idx]
                }
            }
            
        }

        return maxVowelCnt + maxConsonantCnt
    }
}
