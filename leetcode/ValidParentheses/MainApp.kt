/* Copyright (C) 2022 by iamslash */

import java.util.*;

// ([)]

// 294ms 11.52% 34.9MB 39.51%
// stack
// O(N) O(N)
class Solution {
    fun isValid(s: String): Boolean {
        val deq: Deque<Char> = ArrayDeque<Char>()
        val dict = mapOf(
            ')' to '(',
            ']' to '[',
            '}' to '{'
        )
        for (c in s) {
            if (c == ')' || c == ']' || c == '}') {
                if (deq.isNotEmpty() && deq.peekLast() == dict.get(c)) {
                    deq.pollLast()
                } else {
                    return false
                }
            } else {
                deq.addLast(c)
            }
        }
        return deq.isEmpty()
    }
}

fun main() {
    println("Hello World")
}
