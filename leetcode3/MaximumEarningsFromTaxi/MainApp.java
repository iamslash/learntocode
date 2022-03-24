// Copyright (C) 2022 by iamslash

import java.util.*;

// recursive dynamic programming, sort
class Solution {
    private long dfs(int n, int[][] rides, long[] C, int beg) {
        // base
        if (beg == n) {
            return 0;
        }
        // memo
        if (C[beg] > 0) {
            return C[beg];
        }
        // recursion
        long r = 0;
        for (int i = beg; i < n; ++i) {
            int j = i;
            while (j < n && rides[i][1] >= rides[j][0]) {
                j++;
            }
            r = Math.max(rides[i][2] + dfs(n, rides, C, j),
                         dfs(n, rides, C, i+1));
        }
        return C[beg] = r;
    }
    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides, (a, b) -> {
                if (a[0] == b[0] && a[1] == b[1]) {
                    return b[2] - a[2];
                }
                if (a[0] == b[0]) {
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            });
        long[] C = new long[n+1];
        return dfs(n, rides, C, 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
