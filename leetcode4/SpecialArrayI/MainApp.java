// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 43MB 100.00%
// bit manipulation
// O(N) O(1)
class Solution {
    public boolean isArraySpecial(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return true;
        }
        for (int i = 1; i < n; ++i) {
            if ((nums[i-1] & 0x01) == (nums[i] & 0x01)) {
                return false;
            }
        }

        return true;
    }
}
