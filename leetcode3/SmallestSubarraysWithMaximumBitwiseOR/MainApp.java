// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 1 0 2 1 3
//                         i
//       0001 0000 0010 0001 0011
//                         j
// last: 0 0 4 3

// nums: 1 0
//               i
//       0001 0000
//               j
// 
// last: 0 0

// 49ms 67.92% 90.4MB 43.82%
// bit manipulation
// O(N) O(N)
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] last = new int[32];
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = 1;
            for (int j = 0; j < 32; ++j) {
                if ((nums[i] & (1 << j)) > 0) {
                    last[j] = i;
                }
                ans[i] = Math.max(ans[i], last[j] - i + 1);
            }
        }
        return ans;
    }
}
