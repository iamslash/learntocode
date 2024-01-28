// Copyright (C) 2023 by iamslash

import java.util.*;

// a: 12
// b: 5
// n: 4
//
// a: 1010
// b: 0101
//    0000
//    0001
//    0010
//    0100
//    1000

// 1ms 100.00% 40.9MB 27.38%
// brute force
// O(2^N) O(1)
class Solution {
    public int maximumXorProduct(long a, long b, int n) {
        long mod = 1_000_000_007;
        if (n > 0) {
            for (long x = 1L << (n - 1); x > 0; x >>= 1) {
                if ((Math.min(a, b) & x) == 0) {
                    a ^= x;
                    b ^= x;
                }
            }
        }
        return (int)(a % mod * (b % mod) % mod);
    }
}
