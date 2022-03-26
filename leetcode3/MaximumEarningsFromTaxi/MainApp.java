// Copyright (C) 2022 by iamslash

import java.util.*;

// 119ms 56.06% 117.8MB 63.45%
// iterative dynamic programming, sort
// O(N + KlgK) O(N)
// N: n
// K: rides.length
oclass Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides, (a, b) -> a[0] - b[0]);
        // C[i]: max earnings until i point
        long[] C = new long[n+1];
        int j = 0;
        for (int i = 1; i <= n; ++i) {
            C[i] = Math.max(C[i], C[i-1]);
            while (j < rides.length && rides[j][0] == i) {
                C[rides[j][1]] = Math.max(C[rides[j][1]],
                                          C[i] + rides[j][1] - rides[j][0] + rides[j][2]);
                j++;
            }
        }
        return C[n];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
