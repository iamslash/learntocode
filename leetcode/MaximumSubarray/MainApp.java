// Copyright (C) 2024 by iamslash

// 1ms 99.92% 57.2MB 65.16%
// kadane
// O(N) O(1)
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length, locMax = 0, glbMax = Integer.MIN_VALUE;
        for (int num : nums) {
            locMax = Math.max(locMax + num, num);
            glbMax = Math.max(glbMax, locMax);
        }
        return glbMax;
    }
}
