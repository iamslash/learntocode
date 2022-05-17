// Copyright (C) 2022 by iamslash

import java.util.*;

//    lo: 1
//    hi: 2
// diffs: 1 -3 4
//        1 -2 2
//        -2
//         2

//    lo: -4
//    hi:  5
// diffs:  3 -4 5 1 -2
//         3 -1 4 5  3
//        -1
//         5

// Idea: math
//
// if upper - lower < maxVal - minVal, no
// if upper - lower == maxVal - minVal, 1 hidden seq
// if upper - lower == maxVal - minVal + 1, 2 hidden seqs
// if upper - lower == maxVal - minVal + k, k+1 hidden seqs

// 6ms 46.31% 108.6MB 67.79%
// math
// O(N) O(1)
class Solution {
    public int numberOfArrays(int[] diffs, int lower, int upper) {
        long maxVal = 0, minVal = 0, val = 0;
        for (int diff : diffs) {
            val += diff;
            maxVal = Math.max(maxVal, val);
            minVal = Math.min(minVal, val);
        }
        return (int)Math.max(0, (upper - lower) - (maxVal - minVal) + 1);
    }
}
