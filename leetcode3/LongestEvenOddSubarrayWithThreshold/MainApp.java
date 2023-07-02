// Copyright (C) 2023 by iamslash

import java.util.*;

// threshold: 5
//              i
//      nums: 3 2 5 4
//                  j
//    maxLen: 0 

// 18ms 33.33% 44.2MB 33.33%
// two pointers
// O(N) O(1)
class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int n = nums.length, maxLen = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 > 0 || nums[i] > threshold) {
                continue;
            }
            int j = i + 1;
            while (j < n &&
                   nums[j] <= threshold &&
                   nums[j] % 2 == ((j - i) % 2)) {
                j++;
            }
            maxLen = Math.max(maxLen, j - i);
        }
        return maxLen;
    }
}
