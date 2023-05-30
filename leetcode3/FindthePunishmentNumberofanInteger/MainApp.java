// Copyright (C) 2023 by iamslash

import java.util.*;


// dfs(1296, 36)
//   dfs(129, 30)
//      dfs(12, 21) : f
//      dfs(1, 1) : t
//   dfs(12, -60)
//   dfs(1, -260)

// Idea:
// Why we should divide by 10, 100, 1000?
//
// dfs(1000000, 1000)
//   dfs(100000, 1000)
//   dfs(10000, 1000):
//
// When we divide by 10, 100,
//   it does not work for dfs(1000000, 1000)
//   but why?
// Input: 1000
// Output: 6599817
// Expected: 10804657

// 9ms 94.53% 39.5MB 96.72%
// dfs
// O(Nlg_3_N) O(lg_3_N)
class Solution {
    private boolean dfs(int sqr, int num) {
        // base
        if (num < 0 || sqr < num) {
            return false;
        }
        if (sqr == num) {
            return true;
        }
        // recursion
        return dfs(sqr / 10, num - sqr % 10) ||
            dfs(sqr / 100, num - sqr % 100) ||
            dfs(sqr / 1000, num - sqr % 1000);
    }
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int num = 1; num <= n; ++num) {
            int sqr = num * num;
            if (dfs(sqr, num)) {
                ans += sqr;
            }
        }
        return ans;
    }
}

// 16ms 92.00% 40.1MB 89.31%
// dfs
// O(Nlg_6_N) O(lg_6_N)
class Solution {
    private boolean valid(int sqr, int num) {
        // base
        if (num < 0 || sqr < num) {
            return false;
        }
        if (sqr == num) {
            return true;
        }
        // recursion
        return valid(sqr / 10, num - sqr % 10) ||
            valid(sqr / 100, num - sqr % 100) ||
            valid(sqr / 1000, num - sqr % 1000) ||
            valid(sqr / 10000, num - sqr % 10000) ||
            valid(sqr / 100000, num - sqr % 10000) ||
            valid(sqr / 1000000, num - sqr % 1000000);
    }
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int num = 1; num <= n; ++num) {
            int sqr = num * num;
            if (valid(sqr, num)) {
                ans += sqr;
            }
        }
        return ans;
    }
}
