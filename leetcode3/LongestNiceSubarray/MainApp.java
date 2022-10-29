// Copyright (C) 2022 by iamslash

import java.util.*;


//   bm: 1101
//       
//         i
// nums: 1 3 8 48 10
//           j
//
//           i
// nums: 3 1 5 11 13
//           j

// 16ms 27.49% 78.6MB 20.21%
// two pointers, bit manipulation
// O(N) O(1)
class Solution {
    public int longestNiceSubarray(int[] nums) {
        int bm = 0, i = 0, n = nums.length, ans = 0;
        for (int j = 0; j < n; ++j) {
            while ((bm & nums[j]) > 0) {
                bm ^= nums[i++];
            }
            bm |= nums[j];
            ans = Math.max(ans, j - i + 1);
        }
        return ans;
    }
}
