// Copyright (C) 2022 by iamslash

import java.util.*;

//             i
// nums: 1 2 0 1 1 0
//  ans: 1 4

// 0ms 100.00% 42.4MB 75.00%
// brute force
// O(N) O(N)
class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0, j = 0; i < n; ++i) {
            if (i < n - 1 && nums[i] == nums[i+1]) {
                nums[i] += nums[i];
                nums[i+1] = 0;
            }
            if (nums[i] != 0) {
                ans[j++] = nums[i];
            }            
        }
        return ans;
    }
}
