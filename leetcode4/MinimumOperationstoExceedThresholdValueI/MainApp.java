// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 42.3MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums, int k) {
        int cnt = 0;
        for (int num : nums) {
            if (num < k) {
                cnt++;
            }
        }
        return cnt;
    }
}
