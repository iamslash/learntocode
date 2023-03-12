// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: recursive dynamic programming, two pointers
//
// Let's think about recursive function for dynamic programming.
//
// dfs(i, j, diff): matched for i, j, diff?
//      i: index of s1
//      j: index of s2
//   diff: wildcard count of s1 (diff < 0) [-999, 0)
//         wildcard count of s2 (diff > 0) (0,999]
//         no wildcards (diff == 0)
//
// Let's make a chache for dfs()
//   C[i][j][diff]: matched for i, j, diff
//   diff range is [-999, 999]
//
// base section
// i == n && j == m
//   diff == 0
//
// memo section
// C[i][j][diff + 1000] != null
// We add 1000 to diff because range of diff is [-999, 999].
//
// recursion section
// all cases for recursion section
// 0) s1[i] is letter, s2[j] is letter, no wildcards
//    i < n && j < m && diff == 0 && s[i] == s[j] && dfs(i+1, j+1, 0)
// 1) s1[i] is letter, s2 has wildcards
//    i < n && !isDigit(s1[i]) && diff > 0 && dfs(i+1, j, diff-1)
// 2) s1 has wildcards s2[j] is letter
//    j < m && !isDigit(s2[j]) && diff < 0 && dfs(i, j+1, diff+1)
// 3) while s1[i] is digit, skip s1
//    for (int k = i, val = 0, k < n && isDigit(s1[k]); ++k)
// 4) while s2[j] is digit, skip s2
//    for (int k = j, val = 0, k < m && isDigit(s2[k]); ++k)
// 5) others are false
//
//                i
// s1: internationalization
// s2: i18n
//         j
//      k
//
// dfs(0, 0, 0): true
//   dfs(1, 1, 0): true
//     dfs(1, 2, 1): true
//       dfs(2, 2, 0)
//         dfs(2, 3, 8)
//           dfs(3, 3, 7)
//             ...dfs(10, 3, 0)
//                  dfs(11, 4, 0): false
//     dfs(1, 3, 18): true
//       dfs(2, 3, 17): 
//         dfs(3, 3, 16): 
//           ...dfs(19, 3, 0): true
//

// 209ms 65.00% 77.2MB 80.00%
// recursive dunamic programming
// O(AB) O(AB)
class Solution {
    private boolean dfs(Boolean[][][] C, char[] s1, char[] s2, int i, int j, int diff) {
        int n = s1.length, m = s2.length;
        // base
        if (i == n && j == m) {
            return diff == 0;
        }        
        // memo
        if (C[i][j][diff + 1000] != null) {
            return C[i][j][diff + 1000];
        }
        // recursion
        // s1[i] is letter, s2[j] is letter, no wildcards
        if (i < n && j < m && diff == 0 && s1[i] == s2[j]) {
            if (dfs(C, s1, s2, i + 1, j + 1, 0)) {
                return C[i][j][1000] = true;
            }
        }
        // s1[i] is letter, s2 has wildcards
        if (i < n && !Character.isDigit(s1[i]) && diff > 0) {
            if (dfs(C, s1, s2, i + 1, j, diff - 1)) {
                return C[i][j][diff + 1000] = true;
            }
        }
        // s1 has wildcards s2[j] is letter
        if (j < m && !Character.isDigit(s2[j]) && diff < 0) {
            if (dfs(C, s1, s2, i, j + 1, diff + 1)) {
            return C[i][j][diff + 1000] = true;
            }
        }
        // while s1[i] is digit, skip s1
        for (int k = i, val = 0; k < n && Character.isDigit(s1[k]); ++k) {
            val = val * 10 + (s1[k] - '0');
            if (dfs(C, s1, s2, k + 1, j, diff - val)) {
                return C[i][j][diff + 1000] = true;
            }
        }
        // while s2[j] is digit, skip s2
        for (int k = j, val = 0; k < m && Character.isDigit(s2[k]); ++k) {
            val = val * 10 + (s2[k] - '0');
            if (dfs(C, s1, s2, i, k + 1, diff + val)) {
                return C[i][j][diff + 1000] = true;
            }
        }
        return C[i][j][diff + 1000] = false;
    }
    public boolean possiblyEquals(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        Boolean[][][] C = new Boolean[n+1][m+1][2000];
        return dfs(C, s1.toCharArray(), s2.toCharArray(), 0, 0, 0);
    }
}

