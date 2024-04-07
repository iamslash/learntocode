// Copyright (C) 2024 by iamslash

import java.util.*;

//       i
// nums: 1 4 3 3 2
//           j

// sliding window
// O(N) O(1)
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                j++;
            }
            // System.out.printf("i: %d, j: %d\n", i, j);
            maxLen = Math.max(maxLen, j - i);
            i = j - 1;
        }
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && nums[j - 1] > nums[j]) {
                j++;
            }
            maxLen = Math.max(maxLen, j - i);
            i = j - 1;            
        }
        return maxLen;
    }
}
