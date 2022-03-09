/* Copyright (C) 2022 by iamslash */

import java.util.*;

// 709ms 56,82% 70.3MB 54.55%
// priority queue
// O(NlgN) O(N)
class Solution {
    fun repeatLimitedString(s: String, repeatLimit: Int): String {
        var freqs = IntArray(26, { 0 })
        val sb: StringBuilder = StringBuilder();
        val pq: PriorityQueue<IntArray> = PriorityQueue<IntArray>({ a, b -> b[0] - a[0] })
        for (c in s) {
            freqs[c - 'a']++;
        }
        for (i in 0..25) {
            if (freqs[i] > 0) {
                pq.add(intArrayOf(i, freqs[i]))
            }
        }
        while (!pq.isEmpty()) {
            val item: IntArray = pq.poll()
            val code = item[0]
            var freq = item[1]
            val len = Math.min(freq, repeatLimit)
            // println("${code} ${freq} ${len}")
            for (i in 0..len-1) {
                sb.append('a' + code)
            }
            freq -= len;
            if (freq > 0 && !pq.isEmpty()) {
                pq.peek()[1] -= 1;
                sb.append('a' + pq.peek()[0])
                if (pq.peek()[1] == 0) {
                    pq.poll()
                }
                pq.add(intArrayOf(code, freq))
            }
        }
        return sb.toString()
    }
}

fun main() {
    for (i in 0..3) {  // Output: 0 1 2 3             
        print("$i ")
    }
    println()
    for (i in 0 until 3) {  // Output: 0 1 2
        print("$i ")
    }
    println()
    for(i in 2..8 step 2) {      
        print("$i ")
    }
    println()
    for (i in 3 downTo 0) {      
        print("$i ")
    }
    println()
}
