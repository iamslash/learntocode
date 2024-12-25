// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.66% 44.9MB 65.66%
// math
// O(N) O(N)
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; ++i) {
            int j =  (i + nums[i] % n + n) % n;            
            ans[i] = nums[j];
        }

        return ans;
    }
}
