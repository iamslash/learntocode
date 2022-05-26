// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: indutition
//
// p: 1
// p: 2
//     01    1
//     10    2
//     11    3
// p: 3
//    001    1
//    010    6
//    011    1
//    100    6
//    101    1    1
//    110    6    2^p-2
//    111    7    2^p-1
//
//    (2^p-2) * (2^(p-1)-1) + (2^p-1)

// 0ms 100.00% 39.2MB 77.97%
// math
// O(1) O(1)
// difficult
class Solution {
    private int mod = 1_000_000_007;
    private long pow(long base, long n) {
        if (n == 0) {
            return 1L;
        }
        if (n == 1) {
            return base;
        }
        base %= mod;
        long halfn = pow(base, n/2) % mod;
        if (n % 2 == 0) {
            return (halfn * halfn) % mod;
        } 
        return (((halfn * halfn) % mod) * base) % mod;
    }
    public int minNonZeroProduct(int p) {
        long n = 1L << p;
        long rst = (((n-1) % mod) * pow(n-2, n/2-1)) % mod;
        return (int)rst;
    }
}
