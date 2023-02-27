// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: math
//
// Think about how to divide a by b
// 3 998244
//   3        1
//    98244
//    3       1
//     8244
//     2      0
//     2244
//      7     0
//      144
//       4    0
//       24
//        8   1

// 13ms 60.00% 52.9MB 20.00%
// math
// O(N) O(N)
class Solution {
    public int[] divisibilityArray(String word, int m) {
        int n = word.length();
        int[] ans = new int[n];
        long rem = 0;
        for (int i = 0; i < n; ++i) {
            rem = ((10 * rem) + (word.charAt(i) - '0')) % m;
            if (rem == 0) {
                ans[i] = 1;
            }
        }
        return ans;
    }
}
