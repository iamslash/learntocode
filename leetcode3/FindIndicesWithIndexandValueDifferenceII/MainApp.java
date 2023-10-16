// Copyright (C) 2023 by iamslash

// 2ms 100.00% 57.6MB 50.00%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int n = nums.length, maxI = 0, minI = 0;
        for (int i = indexDifference; i < n; ++i) {
            if (nums[i - indexDifference] < nums[minI]) {
                minI = i - indexDifference;
            }
            if (nums[i - indexDifference] > nums[maxI]) {
                maxI = i - indexDifference;
            }
            if (nums[i] - nums[minI] >= valueDifference) {
                return new int[]{minI, i};
            }
            if (nums[maxI] - nums[i] >= valueDifference) {
                return new int[]{maxI, i};
            }
        }
        return new int[]{-1, -1};
    }
}
