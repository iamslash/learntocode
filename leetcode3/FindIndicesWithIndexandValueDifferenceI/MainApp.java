// Copyright (C) 2023 by iamslash

import java.util.*;

// diffI: 1
// diffV: 0   
//  nums: 7 6
//

// 1ms 100.00% 43.7MB 66.67%
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
