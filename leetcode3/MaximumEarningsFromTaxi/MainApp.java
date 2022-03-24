// Copyright (C) 2022 by iamslash

import java.util.*;

// 119ms 56.06% 117.8MB 63.45%
// iterative dynamic programming, sort
// O(N + KlgK) O(N)
// N: n
// K: rides.length
class Solution {
    public long maxTaxiEarnings(int bnd, int[][] rides) {
        Arrays.sort(rides, (a, b) -> a[0] - b[0]);
        // C[i]: max earnings until i point
        long[] C = new long[bnd+1];
        for (int a = 1, i = 0; a <= bnd; ++a) {
            C[a] = Math.max(C[a], C[a-1]);
            while (i < rides.length && rides[i][0] == a) {
                C[rides[i][1]] = Math.max(C[rides[i][1]],
                                          C[a] + rides[i][1] - rides[i][0] + rides[i][2]);
                i++;
            }
        }
        return C[bnd];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
