// Copyright (C) 2024 by iamslash

import java.util.*;

//         
// nums: 1 0 2
//         i
//       0 1 1 2

// 0ms 100.00% 42.1MB 79.12%
// prefix sum
// O(N) O(N)
class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length, cnt = 0;
        int[] ps = new int[n + 1];

        for (int i = 0; i < n; ++i) {
            ps[i + 1] = ps[i] + nums[i]; 
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                int leftSum = ps[i], rightSum = ps[n] - ps[i];
                if (leftSum == rightSum) {
                    cnt += 2;
                } else if (Math.abs(leftSum - rightSum) == 1) {
                    cnt++;
                }
            } 
        }

        return cnt;
    }
}
