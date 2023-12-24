// Copyright (C) 2023 by iamslash

import java.util.*;

//       i
// nums: 6 5 7 8
//           j
//       k

// 5ms 33.33% 43.4MB 66.67%
// brute force
// O(N^3) O(1)
class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int last = -1, flag = 1;
                for (int k = 0; k < n; ++k) {
                    if (i <= k && k <= j) {
                        continue;
                    }
                    if (last >= nums[k]) {
                        flag = 0;
                        break;
                    }
                    last = nums[k];
                }
                if (flag == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
