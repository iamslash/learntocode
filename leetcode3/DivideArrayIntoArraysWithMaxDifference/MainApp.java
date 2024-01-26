// Copyright (C) 2024 by iamslash

import java.util.*;

// 26ms 24.08% 62.4MB 5.03%
// sort
// O(NlgN) O(N)
class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int [][] ans = new int[n/3][3];
        for (int i = 2; i < n; i += 3) {
            if (nums[i] - nums[i-2] > k) {
                return new int[0][];
            }
            ans[i/3] = new int[]{nums[i-2], nums[i-1], nums[i]};
        }
        return ans;
    }
}
