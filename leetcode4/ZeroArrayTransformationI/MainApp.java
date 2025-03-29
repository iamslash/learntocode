// Copyright (C) 2025 by iamslash

import java.util.*;


//  qry:     1,3 0,2
//           
// nums:  4 3 2 1
//        i
// diff: -1 -1 0 1 1
//  dec: -1 -2

// 3ms 79.01% 94.71MB 76.79%
// prefix sum
// O(N + M) O(N)
class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] diffs = new int[n + 1];

        for (int[] query : queries) {
            int l = query[0], r = query[1];
            diffs[l]--;
            diffs[r + 1]++;
        }

        int curDec = 0;

        for (int i = 0; i < n; ++i) {
            curDec += diffs[i];
            if (nums[i] + curDec > 0) {
                return false;
            }
        }

        return true;
    }
}
