// Copyright (C) 2022 by iamslash

import java.util.*;

// hash set
// O(N) O(N)
class Solution {
    private String getLine(int[] src, int[] dst) {
    }
    private int dfs(Set<String> lineSet, int bm) {
    }
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public int minimumLines(int[][] points) {
        int n = points.length;
        if (n <= 1) {
            return n;
        }
        String[][] C = new String[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    C[i][j] = getLine(points[i], points[j]);
                }
            }
        }
        Set<String> lineSet = new HashSet<>();
        return dfs(lineSet, 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
