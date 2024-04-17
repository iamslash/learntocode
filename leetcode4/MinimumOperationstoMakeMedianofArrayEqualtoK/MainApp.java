// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 4
//           i
// nums: 2 5 5 6 8
//         1 1
//           

//    k: 7
//           i
// nums: 2 5 5 6 8
//           2 1
//           

// 30ms 26.56% 62.3MB 73.98%
// sort
// O(NlgN) O(1)
class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        int n = nums.length;
        long ops = 0;
        Arrays.sort(nums);

        for (int i = 0; i <= n/2; ++i) {
            ops += Math.max(0, nums[i] - k);
        }
        
        for (int i = n/2; i < n; ++i) {
            ops += Math.max(0, k - nums[i]);
        }

        return ops;
    }
}
