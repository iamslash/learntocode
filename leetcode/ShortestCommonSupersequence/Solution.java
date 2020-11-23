// Copyright (C) 2019 by iamslash

// 26ms 23.76% 60.2MB 100.00%
// dynamic programming
// O(AB) O(AB)
class Solution {
  private String lcs(String a, String b) {
    int m = a.length(), n = b.length();
    String[][] C = new String[m+1][n+1];
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        C[i][j] = "";
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // System.out.println(String.format("%d %d", i, j));
        if (a.charAt(i) == b.charAt(j))
          C[i+1][j+1] = C[i][j] + a.charAt(i);
        else
          C[i+1][j+1] = C[i+1][j].length() > C[i][j+1].length() ?
              C[i+1][j] : C[i][j+1];
      }
    }
    return C[m][n];
  }
  public String shortestCommonSupersequence(String a, String b) {
    int i = 0, j = 0;
    String ans = "";
    String l = lcs(a, b);
    for (char c : l.toCharArray()) {
      while (a.charAt(i) != c)
        ans += a.charAt(i++);
      while (b.charAt(j) != c)
        ans += b.charAt(j++);
      ans += c; ++i; ++j;
    }
    return ans + a.substring(i) + b.substring(j);
  }
  // public static void main(String[] args) {
  //   String a = "abac";
  //   String b = "cab";
  //   Solution sln = new Solution();
  //   System.out.println(sln.shortestCommonSupersequence(a, b));
  // }
}
