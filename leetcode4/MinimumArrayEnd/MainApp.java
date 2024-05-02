// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: bit manipulation
// 
// n: 3
// x: 4
//    0100
//    0101
//    0110
//    0111
//
// bm = (bm + 1) | x

// 1736ms 24.12% 40.5MB 91.06%
// bit manipulation
// O(N) O(1)
class Solution {
    public long minEnd(int n, int x) {
        long bm = x;

        while (--n > 0) {
            bm = (bm + 1) | x;
        }

        return bm;
    }
}
