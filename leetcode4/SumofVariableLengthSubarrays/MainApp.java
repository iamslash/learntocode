// Copyright (C) 2025 by iamslash

import java.util.*;

//           i
// nums:   2 3 1
//   ps: 0 2 5 1
//
//         

// 1ms 99.98% 43.35MB 95.51%
// partial sum
// O(N) O(N)
class Solution {
    public int subarraySum(int[] nums) {
        int n = nums.length, sum = 0;
        int[] ps = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            ps[i + 1] = ps[i] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            int start = Math.max(0, i - nums[i]);
            sum += ps[i + 1] - ps[start];
        }

        return sum;
    }
}
