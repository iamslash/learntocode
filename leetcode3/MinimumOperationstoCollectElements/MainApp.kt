/* Copyright (C) 2023 by iamslash */

import java.util.*;

// 175ms 53.85% 35.1MB 84.62%
// hash set
// O(N) O(N)
class Solution {
    fun minOperations(nums: List<Int>, k: Int): Int {
        val numSet: MutableSet<Int> = mutableSetOf()
        val n: Int = nums.size
        for (i in n-1 downTo 0) {
            if (nums.get(i) <= k) {
                numSet.add(nums.get(i))
            }
            if (numSet.size == k) {
                return n - i
            }
        }
        return -1;
    }
}

fun main() {
    println("Hello World")
}
