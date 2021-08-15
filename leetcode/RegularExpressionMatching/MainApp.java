// Copyright (C) 2021 by iamslash

// s: a a
// p: a *
//
//         j
//       a *
//     t f t
//   a f t t
// i a f f ?
//


// iterative dynamic programming
// O(HW) O(HW)
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] C = new boolean[m+1][n+1];
        C[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            C[0][j] = (p.charAt(j-1) == '*') && C[0][j-2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p.charAt(j-1) == '*') {
                    C[i][j] = C[i][j-2] || 
                        (C[i-1][j] && (p.charAt(j-2) == '.' || p.charAt(j-2) == s.charAt(i-1)));
                } else {
                    C[i][j] = C[i-1][j-1] && (p.charAt(j-1) == '.' || p.charAt(j-1) == s.charAt(i-1));
                }
            }
        }
        return C[m][n];
    }
}

// // DFS
// class Solution {
//     public boolean isMatch(String s, String p) {
//         // base
//         if(p.isEmpty()) {
//             return s.isEmpty();
//         }
//         // recursion
//         boolean firstMatch = s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');
//         if (p.length() >= 2 && p.charAt(1) == '*') {
//             return (firstMatch && isMatch(s.substring(1), p)) || isMatch(s, p.substring(2));
//         }
//         return firstMatch && isMatch(s.substring(1), p.substring(1));
//     }
// }

public class MainApp {
  public static void main(String[] args) {
  }
}
