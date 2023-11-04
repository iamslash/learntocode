// Copyright (C) 2023 by iamslash

import java.util.*;

//  tgt: 9
//             i
// nums: 1 2 3 4 5
//
//               .         .
//    C: 0 1 1 1 2 2 - - - 3
//                         a

// Idea: iterative dynamic programming
//
// It is similar with coin change progblem.
// C[amount] means max count of nums for amount.
// Init C[amount] with MIN_VALUE and C[0] = 0 for seed value.
// Traverse nums sequentially.
//   Traverse amount in [target, 1].
//     C[amount] = max(C[amount], C[amount - num] + 1)
//
// 22ms 99.03% 43.3MB 83.62%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int[] C = new int[target + 1];
        Arrays.fill(C, Integer.MIN_VALUE);
        C[0] = 0;
        for (int num : nums) {
            for (int amt = target; amt >= num; --amt) {
                C[amt] = Math.max(C[amt], C[amt - num] + 1);
            }
        }
        if (C[target] < 0) {
            return -1;
        }
        return C[target];
    }
}
