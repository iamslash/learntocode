// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 45.6MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public int[] orArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n - 1];

        for (int i = 0; i < ans.length; ++i) {
            ans[i] = nums[i] | nums[i + 1];
        }

        return ans;
    }
}
