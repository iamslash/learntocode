// Copyright (C) 2024 by iamslash

import java.util.*;

// 3ms 100.00% 65MB 20.77%
// brute force
// O(N) O(N)
class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        int n = nums.length, m = queries.length, pos = 0;
        int[] ans = new int[m];
        int[] xths = new int[n];

        for (int i = 0; i < n; ++i) {
            if (nums[i] == x) {
                xths[pos++] = i;
            }
        }

        for (int i = 0; i < m; ++i) {
            int idx = queries[i] - 1;
            ans[i] = idx < pos ? xths[idx] : -1;
        }

        return ans;
    }
}
