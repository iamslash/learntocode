/* Copyright (C) 2025 by iamslash */

import kotlin.math.abs;

// 1ms 100.00% 41.19MB 100.00%
// math
// O(1) O(1)
class Solution {

    private tailrec fun gcd(a: Int, b: Int): Int {
        // base
        if (b == 0) {
            return abs(a);
        }
        // recursion
        return gcd(b, a % b);
    }
    
    fun gcdOfOddEvenSums(n: Int): Int {
        val nn = n + n;
        val sum = nn * (nn + 1) / 2;
        val sumOdd = (sum - n) / 2;
        val sumEven = sumOdd + n;

        return gcd(sumEven, sumOdd);
    }
}
