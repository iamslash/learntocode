// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 44.4MB 100.00%
// sliding window
// O(NM) O(1)
class Solution {
    private boolean match(int[] nums, int[] pattern, int beg) {
        int m = pattern.length;
        for (int i = 0; i < m; ++i) {
            int j = beg + 1 + i;
            if (pattern[i] == 1) {
                if (nums[j - 1] >= nums[j]) {
                    return false;
                }
            } else if (pattern[i] == 0) {
                if (nums[j - 1] != nums[j]) {
                    return false;
                }
            } else {
                if (nums[j - 1] <= nums[j]) {
                    return false;
                }
            }
        }
        return true;
    }
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.length, m = pattern.length, cnt = 0;
        for (int i = 0; i + m < n; ++i) {
            if (match(nums, pattern, i)) {
                cnt++;
            }
        }
        return cnt;
    }
}
