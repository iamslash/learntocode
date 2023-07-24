// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 58.2MB 100.00%
// backward traverse
// O(N) O(1)
class Solution {
    public long maxArrayValue(int[] nums) {
        int n = nums.length;
        long sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > sum) {
                sum = nums[i];
            } else {
                sum = sum + nums[i];
            }
        }
        return sum;
    }
}
