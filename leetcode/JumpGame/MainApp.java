// Copyright (C) 2024 by iamslash

import java.util.*;

//                 i
// nums: 2 3 1 1 4
//               j

// 3ms 56.42% 45.8MB 30.00%
// two pointers
// O(N) O(1)
class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (i > j) {
                break;
            }
            j = Math.max(j, i + nums[i]);
        }
        return j >= n - 1;
    }
}
