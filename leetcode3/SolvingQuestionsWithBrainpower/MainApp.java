// Copyright (C) 2022 by iamslash

import java.util.*;

// 12ms 44.59% 106MB 79.10%
// recursive dynamic programming
// O(N) O(N)
class Solution {
    private long dfs(int[][] Q, long[] C, int u) {
        int n = Q.length;
        // base
        if (u == n) {
            return 0;
        }
        // memo
        if (C[u] > 0) {
            return C[u];
        }
        // recursion
        int v = Math.min(n, u + 1 + Q[u][1]);
        long r = Math.max(Q[u][0] + dfs(Q, C, v),
                          dfs(Q, C, u+1));
        return C[u] = r;
    }
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] C = new long[n];
        Arrays.fill(C, -1);
        return dfs(questions, C, 0);
    }
}

// 12ms 44.59% 106.9MB 65.28%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long C[] = new long[n+1];
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0], skip = questions[i][1];
            int j = Math.min(i + 1 + skip, n);
            C[i] = Math.max(points + C[j], C[i+1]);
        }
        return C[0];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
