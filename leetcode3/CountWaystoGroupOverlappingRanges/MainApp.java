// Copyright (C) 2023 by iamslash

import java.util.*;


// ranges: 1,3 10,20 2,5 4,8
//         0         5        10        15        20
//         . . . . . . . . . . . . . . . . . . . . . 
//           -----
//             -------
//                 ---------
//                             ---------------------

// Idea: sort, permutation
//
// If the number of group is n, the answer is 2 ^ n.
// Sort by rarnge[0] asc.
// Merge and count.

// 15ms 98.92% 101.4MB 19.18%
// sort, permutation
// O(NlgN) O(1)
class Solution {
    public int countWays(int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int n = ranges.length, mod = 1_000_000_007, lastEnd = -1, ans = 1;
        for (int[] range : ranges) {
            if (lastEnd < range[0]) {
                ans = ans * 2 % mod;
            }
            lastEnd = Math.max(lastEnd, range[1]);
        }
        return ans;
    }
}
