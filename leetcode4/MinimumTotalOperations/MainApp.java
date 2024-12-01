// Copyright (C) 2024 by iamslash

import java.util.*;

//         i
// nums: 1 4 2
// 

// backward probe
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, cnt = 0;

        if (n == 1) {
            return 0;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] != nums[i + 1]) {
                cnt++;
            }
        }

        return cnt;
    }
}
