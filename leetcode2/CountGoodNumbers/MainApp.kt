/* Copyright (C) 2021 by iamslash */

// 128ms 86.67% 33MB 93.33%
// divide and conquor
// O(lgL) O(lgL)
// L: length of N
const val MOD = 1000000007L
class Solution {
    fun modPow(x: Long, y: Long): Long {
        // base
        if (y == 0L) {
            return 1
        }
        // recursion
        val p = modPow(x, y/2)
        var extra = x
        if (y % 2L == 0L) {
            extra = 1
        }
        return p * p * extra % MOD
    }
    fun countGoodNumbers(n: Long): Int {
        return (modPow(5, (n+1)/2) * modPow(4, n/2) % MOD).toInt()
    }
}

fun main() {
    println("Hello World")
}
