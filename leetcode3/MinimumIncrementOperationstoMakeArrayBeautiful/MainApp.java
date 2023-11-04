// Copyright (C) 2023 by iamslash

import java.util.*;


//    k: 4
//       i
// nums: 2 3 0 0 2
//   C1: 0
//   C2: 0
//   C3: 0
//   C4: 0

// 2ms 100.00% 60.2MB 86.67%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long minIncrementOperations(int[] nums, int k) {
        // C1: increment of nums[i - 3]
        // C2: increment of nums[i - 2]
        // C3: increment of nums[i - 1]
        // C4: increment of nums[i]
        long C1 = 0, C2 = 0, C3 = 0, C4 = 0;
        for (int num : nums) {
            C4 = Math.min(C1, Math.min(C2, C3)) + Math.max(k - num, 0);
            C1 = C2;
            C2 = C3;
            C3 = C4;
        }
        return Math.min(C1, Math.min(C2, C3));
    }
}
