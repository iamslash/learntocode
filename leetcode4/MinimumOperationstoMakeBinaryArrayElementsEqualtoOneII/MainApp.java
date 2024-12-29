// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 0 1 1 0 1
//       1 0 0 1 0
//       1 1 1 0 1
//       1 1 1 1 0
//       1 1 1 1 1

// 5ms 98.52% 57.35% 34.07%
// linear traversal
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, cnt = 0, last = nums[0];
        if (last == 0) {
            cnt++;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != last) {
                cnt++;
                last = nums[i];
            }
        }

        return cnt;
    }
}
