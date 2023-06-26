// Copyright (C) 2023 by iamslash

import java.util.*;

//       p
// nums: 2 3 6
// 

// 192ms 82.58% 45.5MB 86.35%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    int mod = 1_000_000_007;
    int endMask = 0;
    private int dfs(int[] nums, int[][] C, int mask, int pos) {
        int n = nums.length;
        // base
        if (mask == endMask) {
            return 1;
        }
        // memo
        if (C[pos][mask] >= 0) {
            return C[pos][mask];
        }
        // recursion
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0 &&
                (mask == 0 ||
                 (nums[pos] % nums[i] == 0) ||
                 (nums[i] % nums[pos] == 0))) {
                cnt = (cnt + dfs(nums, C, mask | (1 << i), i)) % mod;
            }
        }
        return C[pos][mask] = cnt;
    }
    public int specialPerm(int[] nums) {
        int n = nums.length;
        // C[bitmask][index]
        endMask = (1 << n) - 1;
        int[][] C = new int[n][1 << n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(C[i], -1);
        }
        return dfs(nums, C, 0, 0);
    }
}
