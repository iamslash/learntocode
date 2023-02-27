// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 42.9MB 66.67%
// partial sum
// O(N) O(N)
class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int n = nums.length;
        int[] ps = new int[n+1];
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = Math.abs(ps[i] - ps[n] + ps[i+1]);
        }
        return ans;
    }
}
