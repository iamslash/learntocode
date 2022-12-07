// Copyright (C) 2022 by iamslash

import java.util.*;

//              i
// nums: 6 6 7 13
//  val: 1 2 2  2
//  ans: 7
//
//       6
//         6
//       6 6
//         6 7
//       6 6 7
//         6 7 13
//       6 6 7 13

// 6ms 100.00% 68.7MB 100.00%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long evenProduct(int[] nums) {
        long ans = 0;
        int n = nums.length;
        for (int i = 0, val = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                val = i + 1;
            }
            ans += val;
        }
        return ans;
    }
}
