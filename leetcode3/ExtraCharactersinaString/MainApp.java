// Copyright (C) 2023 by iamslash

import java.util.*;

// 58ms 23.10% 44.5MB 46.19%
// recursive dynamic programming
// O(S^2D) O(S^2)
class Solution {
    private int dfs(String s, Set<String> dictSet, int[] C, int idx) {
        int n = s.length();
        // base
        if (idx == n) {
            return 0;
        }
        // memo
        if (C[idx] >= 0) {
            return C[idx];
        }
        // recursion
        int rst = Integer.MAX_VALUE;
        for (int j = idx; j < n; ++j) {
            String ss = s.substring(idx, j + 1);
            if (dictSet.contains(ss)) {
                rst = Math.min(rst, dfs(s, dictSet, C, j + 1));
            } else {
                rst = Math.min(rst, j - idx + 1 + dfs(s, dictSet, C, j + 1));
            }
        }
        return C[idx] = rst;
    }
    public int minExtraChar(String s, String[] dict) {
        int[] C = new int[s.length() + 1];
        Arrays.fill(C, -1);
        Set<String> dictSet = new HashSet<>(Arrays.asList(dict));
        return dfs(s, dictSet, C, 0);
    }
}

// 54ms 51.31% 44.3MB 66.24%
// iterative dynamic programming
// O(S^2) O(S^2)
class Solution {
    public int minExtraChar(String s, String[] dict) {
        int n = s.length();
        Set<String> dictSet = new HashSet<>(Arrays.asList(dict));
        int[] C = new int[n + 1];
        Arrays.fill(C, n + 1);
        C[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                String ss = s.substring(j, i);
                if (dictSet.contains(ss)) {
                    C[i] = Math.min(C[i], C[j]);
                } else {
                    C[i] = Math.min(C[i], C[j] + i - j);
                }
            }
        }
        return C[n];
    }
}

// 42ms 85.62% 44MB 97.87%
// iterative dynamic programming
// O(S^2) O(S^2)
class Solution {
    public int minExtraChar(String s, String[] dict) {
        int n = s.length();
        int[] C = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            C[i] = C[i - 1] + 1;
            for (String word : dict) {
                int m = word.length();
                if (i >= m && s.substring(i - m, i).equals(word)) {
                    C[i] = Math.min(C[i], C[i - m]);
                }
            }
        }
        return C[n];
    }
}
