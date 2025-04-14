// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 92.51% 45.78MB 5.38%
// math
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums, int k) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        return sum % k;        
    }
}
