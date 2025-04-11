// Copyright (C) 2025 by iamslash

import java.util.*;


// org:   1   2   3   4
//                    i
// bnd: 1,2 2,3 3,4 4,5
//
//   l:   1   2   3   4
//   r:   2   3   4   5

// org:    1   2   3   4
//                     i
// bnd: 1,10 2,9 3,8 4,7
//
//   l:    1   2   3   4
//   r:   10   9   8   7

// 1ms 100.00% 97.87MB 73.59%
// linear traversal
// O(N) O(1)
class Solution {
    public int countArrays(int[] original, int[][] bounds) {
        int left = bounds[0][0];
        int right = bounds[0][1];
        int n = original.length;

        for (int i = 1; i < n; ++i) {
            int diff = original[i] - original[i - 1];

            left = Math.max(left + diff, bounds[i][0]);
            right = Math.min(right + diff, bounds[i][1]);

            if (left > right) {
                return 0;
            }
        }

        return right - left + 1;
    }
}
