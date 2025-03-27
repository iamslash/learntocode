// Copyright (C) 2025 by iamslash

import java.util.*;


// nums: 3 4 1 2 6
//   ps: 0 0 0 0 1

// nums: 4 3 1 6
//   ps: 0 0 1 1

// Idea: prefix sum
//
// nums: 3 4 1 2 6
//   ps: 0 0 0 0 1
//
// The answer of [0, 4] is ps[4] - ps[0] == 0.
//
// 3ms 84.12% 98.82MB 28.27%
// prefix sum
// O(N) O(N)
class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length, m = queries.length;
        int[] ps = new int[n];
        boolean[] ans = new boolean[m];

        for (int i = 1; i < n; ++i) {
            ps[i] = ps[i - 1];
            if (nums[i - 1] % 2 == nums[i] % 2) {
                ps[i]++;
            } 
        }

        for (int i = 0; i < m; ++i) {
            int j = queries[i][0], k = queries[i][1];
            int cnt = ps[k] - ps[j];
            if (cnt == 0) {
                ans[i] = true;
            }
        }

        return ans;
    }
}
