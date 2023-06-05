// Copyright (C) 2023 by iamslash

import java.util.*;

//           i
// nums: 2 4 1 3
//          j

// 2ms 100.00% 43.2MB 20.00%
// math
// O(N) O(1)
class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int n = nums.length;
        int minIdx = 0, maxIdx = n-1, minNum = nums[0], maxNum = nums[n-1];
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minNum) {
                minIdx = i;
                minNum = nums[i];
            }
            if (nums[i] > maxNum) {
                maxIdx = i;
                maxNum = nums[i];
            }
        }
        // System.out.printf("minIdx: %d, maxIdx: %d\n", minIdx, maxIdx);
        if (maxIdx < minIdx) {
            return minIdx + (n - 1 - maxIdx) - 1;
        }
        return minIdx + (n - 1 - maxIdx);
    }
}
