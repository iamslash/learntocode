/* Copyright (C) 2021 by iamslash */

class Solution {
    fun countTriples(n: Int): Int {
        val squares = BooleanArray(n*n + 1)
        for (i in 1..n) {
            squares[i*i] = true
        }
        var cnt = 0
        for (a in 1..n) {
            for (b in 1..n) {
                
            }
        }
        return cnt
    }
}

fun main() {
    println("Hello World")
}
