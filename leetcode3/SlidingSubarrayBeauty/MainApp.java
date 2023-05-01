// Copyright (C) 2023 by iamslash

import java.util.*;

//    k: 3
//    x: 2
//               i
//   nums: 1 -1 -3 -2 3
//         j
// freqs: -3 -1
//         1  1

// 55ms 59.59% 60.1MB 40.84%
// sliding window
// O(N) O(N)
class Solution {
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        int n = nums.length;
        int[] freqs = new int[50], ans = new int[n - k + 1];
        for (int i = 0; i < n; ++i) {
            // Process end of window
            if (nums[i] < 0) {
                freqs[nums[i] + 50]++;                
            }
            // Process begin of window
            if (i - k >= 0 && nums[i - k] < 0) {
                freqs[nums[i - k] + 50]--; 
            }
            // Skip small window
            if (i - k + 1 < 0) {
                continue;
            }
            // Calculate count
            for (int j = 0, cnt = 0; j < 50; ++j) {
                cnt += freqs[j];
                if (cnt >= x) {
                    ans[i - k + 1] = j - 50;
                    break;
                }
            }
        }
        return ans;
    }
}
