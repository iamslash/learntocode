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

// Wrong Answer
//
// Input:
// 53449611838892
// 712958946092406
// 6
// Output:
// -1660450
// Expected:
// 231850918
//
// brute force
// O(2^N) O(1)
class Solution {
    public int maximumXorProduct(long a, long b, int n) {
        int mod = 1_000_000_007;
        if (n > 0) {
            for (long x = 1L << (n - 1); x > 0; --x) {
                if ((Math.min(a, b) & x) == 0) {
                    a ^= x;
                    b ^= x;
                }
            }
        }
        return (int)(a % mod * (b % mod) % mod);
    }
}
