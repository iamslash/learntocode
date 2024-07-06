// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 41.9MB 44.29%
// math
// O(N) O(1)
class Solution {
    public int minimumOperations(int[] nums) {
        int cnt = 0;

        for (int num : nums) {
            if (num % 3 != 0) {
                cnt++;
            } 
        }

        return cnt;
    }
}
