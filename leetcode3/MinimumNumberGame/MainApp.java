// Copyright (C) 2023 by iamslash

import java.util.*;

// 3ms 50.0% 44.8MB 50.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int[] numberGame(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < n; i += 2) {
            int t = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = t;
        }
        return nums;
    }
}
