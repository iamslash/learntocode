/* Copyright (C) 2021 by iamslash */

// 216ms 100.00% 37.7MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
    fun sumGame(num: String): Boolean {
        val n = num.length
        var ans = 0.0
        for (i in 0 until n) {
            var delta = 1.0
            if (i < n/2) {
                delta = -1.0
            }
            if (num[i] == '?') {
                delta *= 4.5
            } else {
                delta *= num[i] - '0'
            }
            ans += delta
        }
        return ans != 0.0
    }
}

fun main() {
    println("Hello World")
}
