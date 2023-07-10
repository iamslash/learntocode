// Copyright (C) 2023 by iamslash

import java.util.*;

//         i
// nums: 2 3 4 3 4
//                 j

// 3ms 89.09% 43MB 93.71%
// two pointers
// O(N) O(1)
class Solution {
    public int alternatingSubarray(int[] nums) {
        int n = nums.length, maxLen = -1;
        for (int i = 0, j = 0; i < n - 1 && j < n; i++) {
            if (nums[i] + 1 != nums[i + 1]) {
                continue;
            }
            j = i + 1;
            int delta = 1;
            while (j < n && nums[j - 1] + delta == nums[j]) {
                j++;
                delta *= -1;
            }
            // System.out.printf("i: %d, j: %d\n", i, j);
            maxLen = Math.max(maxLen, j - i);
        }
        return maxLen;
    }
}
