// Copyright (C) 2022 by iamslash

import java.util.*;

// 5ms 99.26% 48.8MB 62.85%
// binary search
// O(MlgN) O(M)
class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int n = nums.length, m = queries.length;
        int[] ans = new int[m];
        // Build ps
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        // Binary search
        for (int i = 0; i < m; ++i) {
            int j = Arrays.binarySearch(nums, queries[i]);
            ans[i] = Math.abs(j + 1);
        }
        return ans;
    }
}
