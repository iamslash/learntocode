// Copyright (C) 2024 by iamslash

import java.util.*;


// n: 0101
//   
// x: 0011
//    0100
//    0101
//    ----
//    0000

// n: 1001
// x: 0111
//    1000
//    1001
//    ----
//    0000

// Idea: bit manipulation
//
// Find MSB.
// Subtract 1 from MSB.
// That is the x.
//
// n: 1001
// x: 0111
//    1000
//    1001
//    ----
//    0000

// 3ms 100.00% 43.5MB 73.33%
// math
// O(lgN) O(1)
class Solution {
    public long maxNumber(long n) {
        long x = 1;

        // Find MSB
        while ((x << 1) <= n) {
            x <<= 1;
        }

        // subtract 1 from MSB
        return x - 1;
    }
}
