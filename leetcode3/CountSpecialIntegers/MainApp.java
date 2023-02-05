// Copyright (C) 2023 by iamslash

import java.util.*;

// 1 digit nums: 9
// 2 digit nums: 9 * 9
// 3 digit nums: 9 * 9 * 8
// 4 digit nums: 9 * 9 * 8 * 7


//      i
// s: 2 4 2 4

// 0ms 100.00% 39.2MB 77.36%
// dfs
// O(logN) O(logN)
class Solution {
    private int count(int digitCnt, int candCnt) {
        // base
        if (digitCnt == 0) {
            return 1;
        }
        // recursion
        return (candCnt - digitCnt + 1) * count(digitCnt - 1, candCnt);
    }
    private int dfs(String s, int bm, int i) {
        int n = s.length();
        // base
        if (i >= n) {
            return 1;
        }
        int ans = 0, digit = s.charAt(i) - '0', cand = 0;        
        if (i == 0) {
            // candidate digit starts from 1
            cand = 1;
        }
        while (cand < digit) {
            if ((bm & (1 << cand)) == 0) {
                ans += count(n - i - 1, 9 - i);
            }
            cand++;
        }        
        if ((bm & (1 << digit)) == 0) {
            ans += dfs(s, bm + (1 << digit), i + 1);
        }
        return ans;
    }
    public int countSpecialNumbers(int n) {
        String s = Integer.toString(n);
        int ans = dfs(s, 0, 0);
        for (int i = 1; i < s.length(); ++i) {
            ans += 9 * count(i - 1, 9);
        }
        return ans;
    }
}
