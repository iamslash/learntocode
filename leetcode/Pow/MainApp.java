// Copyright (C) 2024 by iamslash

// x: 2
// n: 10
//
//                . 
//   x:  2 4 16 256
//   n: 10 5  2   1
// ans:  1 2  8 128

// Idea: math
//
// x: 7
// n: 11
//
// binary representation of 11
// 11 = 1 0 1 1
//      8 4 2 1
//
// 7^11 = 7^8 * 7^2 * 7^1
//        7^(8 + 2 + 1)
//

// 0ms 100.00% 41.7MB 88.16%
// math
// O(lgN) O(1)
class Solution {
    public double myPow(double x, int n) {
        double ans = 1;

        if (n < 0) {
            n = -n;
            x = 1 / x;
        }

        while (n != 0) {
            if ((n & 1) != 0) {
                ans *= x;
            }
            x *= x;
            n >>>= 1;
        }

        return ans;
    }
}
