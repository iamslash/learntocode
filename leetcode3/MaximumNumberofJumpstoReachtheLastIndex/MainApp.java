// Copyright (C) 2023 by iamslash

import java.util.*;


//  tgt: 2
//                 i
// nums: 1 3 6 4 1 2
//             j
//    C: 0 1 - 2 2 3

// Idea: iterative dynamic programming
//
// C[i]: max path to index i
// C[i] = max(C[i], C[j] + 1)
//
// 18ms 85.66% 43.8MB 64.34%
// Iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int maximumJumps(int[] nums, int target) {
        int n = nums.length;
        int[] C = new int[n];
        Arrays.fill(C, -1);
        C[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (Math.abs(nums[i] - nums[j]) <= target && C[j] != -1) {
                    C[i] = Math.max(C[i], C[j] + 1);
                }
            }
        }
        return C[n-1];
    }
}
















