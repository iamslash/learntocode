// Copyright (C) 2023 by iamslash

import java.util.*;

//       i
// nums: 2 3 6 1 9 2

// Idea: iterative dynamic programming
//
// nums[i] comes from same parity or different parity.
// ans[0] stands for maximum sum of parity even
// ans[1] stands for maximum sum of parity odd
// ans[parity] = max(ans[parity], ans[parity ^ 1] - x) + nums[i]
//
// 5ms 100.00% 55.8MB 64.89%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long maxScore(int[] nums, int x) {
        int n = nums.length;
        long[] ans = new long[]{-x, -x};
        ans[nums[0] & 1] = nums[0];
        for (int i = 1; i < n; ++i) {
            int parity = nums[i] & 1;
            ans[parity] = Math.max(ans[parity], ans[parity ^ 1] - x) + nums[i];
        }
        return Math.max(ans[0], ans[1]);
    }
}
