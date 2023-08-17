// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 99.07% 42.7MB 87.19%
// greedy
// O(N) O(1)
class Solution {
    public boolean canSplitArray(List<Integer> nums, int m) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums.get(i) + nums.get(i + 1) >= m) {
                return true;
            }
        }
        return n < 3;
    }
}
