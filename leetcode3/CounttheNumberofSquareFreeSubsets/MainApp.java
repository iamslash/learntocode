// Copyright (C) 2023 by iamslash

import java.util.*;

// 647ms 26.57% 63.1MB 31.25%
// recursive dynamic programming
// O(N) O(N)
// N: then len of nums
class Solution {
    private int mod = 1_000_000_007;
    private int[][] C = new int[1001][1 << 11];
    private int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    private int getBm(int num) {
        int bm = 0;
        for (int i = 0; i < 10; ++i) {
            int cnt = 0;
            while (num > 0 && (num % primes[i] == 0)) {
                num /= primes[i];
                if (++cnt > 1) {
                    return -1;
                }
            }
            if (cnt == 1) {
                bm |= (1 << (i + 1));
            }
        }
        return bm;
    }
    private int dfs(int[] nums, int idx, int prodBm) {
        int n = nums.length;
        // base
        if (idx >= n) {
            return 1;
        }
        // memo
        if (C[idx][prodBm] >= 0) {
            return C[idx][prodBm];
        }
        // recursion
        // Exclude idx
        int cnt = dfs(nums, idx + 1, prodBm);
        // Include Idx
        int bm = getBm(nums[idx]);
        if ((prodBm & bm) == 0) {
            cnt = (cnt + dfs(nums, idx + 1, prodBm | bm)) % mod;
        }
        return C[idx][prodBm] = cnt % mod;
    }
    public int squareFreeSubsets(int[] nums) {
        // C[i][j] stands for the count of cases when index is i,
        // bitmask is j.
        for (int i = 0; i < 1001; ++i) {
            Arrays.fill(C[i], -1);
        }
        // Subtract empty subset.
        return (dfs(nums, 0, 1) - 1 + mod) % mod;
    }
}
