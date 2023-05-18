// Copyright (C) 2023 by iamslash

import java.util.*;

//      k: 1
//            i
//   nums: 12 9
// rights:    0

// 3ms 99.59% 58.8MB 51.91%
// prefix sum
// O(N) O(N)
class Solution {
    public long maximumOr(int[] nums, int k) {
        int n = nums.length;
        long left = 0;
        long[] rights = new long[n];
        long ans = 0;
        for (int i = n - 2; i >=0; --i) {
            rights[i] = rights[i+1] | nums[i+1];
        }
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, left | (long)nums[i] << k | rights[i]);
            left |= (long)nums[i];
        }
        return ans;        
    }
}
