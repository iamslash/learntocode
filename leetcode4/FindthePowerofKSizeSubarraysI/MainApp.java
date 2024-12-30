// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 3
//               i
// nums: 1 2 3 4 3 2 5
//  asc:   2 3 4
//  ans:     3 4 - - -
//

//    k: 2
//       i
// nums: 1 3 4
//  asc: 1
//  ans: -

// 1ms 100.00% 45.73MB 9.19%
// linear traversal
// O(N) O(N)
class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length, consecutiveAscCnt = 0;
        int[] ans = new int[n - k + 1];

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i - 1] + 1 == nums[i]) {
                consecutiveAscCnt++;
            } else {
                consecutiveAscCnt = 1;
            }

            if (i >= k - 1) {
                ans[i - k + 1] = consecutiveAscCnt >= k ? nums[i] : -1;
            } 
        }

        return ans;
    }
}
