// Copyright (C) 2025 by iamslash

import java.util.*;




// locked: 1 0 0
//   nums: 2 2 1
//           i
//         

// locked: 1 1 0
//   nums: 2 2 1
//           i
//         2 1 2
//         i

// lock: 1 0 1 1 0 1 0
// nums: 1 2 1 1 3 2 2
//                   i
// cMax: 1 2 2 2 3 3
// lcks: 1 1 0 0 0 0
//  ans: 0 0 1 1 1 1 

// 7ms 100.00% 63.60MB 55.56%
// O(N) O(1)
class Solution {
    public int minUnlockedIndices(int[] nums, int[] locked) {
        int curMax = 1, locks = 0, ans = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > curMax) {
                curMax = nums[i];
                locks = 0;
            }
            
            if (nums[i] < curMax) {
                if (nums[i] + 1 < curMax) {
                    return -1;
                }
                ans += locks;
                locks = 0;
            }
            
            locks += locked[i];
        }

        return ans;
    }
}
