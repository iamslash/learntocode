// Copyright (C) 2023 by iamslash

import java.util.*;

// 10ms 100.00% 58.8MB 100.00%
// two pointers
// O(N) O(1)
class Solution {
    public int maximizeGreatness(int[] nums) {
        Arrays.sort(nums);
        int j = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[j]) {
                j++;
            }
        }
        return j;
    }
}
