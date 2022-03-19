/* Copyright (C) 2022 by iamslash */

import java.util.*;

// ([)]

// 192ms 72.56% 35.1MB 32.51%
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
            if (c == '(' || c == '[' || c == '{') {
                deq.offerLast(c)
            } else if (deq.isNotEmpty() && deq.peekLast() == dict.get(c)) {
                deq.pollLast()
            } else {
                return false
            }
        }
        return deq.isEmpty()
    }
}

fun main() {
    println("Hello World")
}
