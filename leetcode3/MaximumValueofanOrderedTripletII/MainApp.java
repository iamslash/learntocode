// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 99.60% 56.2MB 87.14%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, maxa = 0, maxab = 0;
        for (int num : nums) {
            ans = Math.max(ans, maxab * num);
            maxab = Math.max(maxab, maxa - num);
            maxa = Math.max(maxa, num);
        }
        return ans;
    }
}
