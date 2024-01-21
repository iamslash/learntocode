// Copyright (C) 2024 by iamslash


//              i
// nums: 10 3 1 1
// min0: 10
// min1:  1
// min2:  3

// 1ms 100.00% 44.2MB 50.00%
// math
// O(N) O(1)
class Solution {
    public int minimumCost(int[] nums) {
        int min0 = nums[0], n = nums.length;
        int min1 = nums[1] < nums[2] ? nums[1] : nums[2];
        int min2 = nums[1] < nums[2] ? nums[2] : nums[1];
        for (int i = 3; i < n; ++i) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return min0 + min1 + min2;
    }
}
