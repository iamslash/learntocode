// Copyright (C) 2023 by iamslash

import java.util.*;

// 4ms 100.00% 44.2MB 17.77%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int minimumOperations(List<Integer> nums) {
        int n = nums.length;
        int[] C = new int[]{n, n, n, n};
        for (int num : nums) {
            C[num]--;
            C[2] = Math.min(C[2], C[1]);
            C[3] = Math.min(C[3], C[2]);
        }
        return C[3];
    }
}
