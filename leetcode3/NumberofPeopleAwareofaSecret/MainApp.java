// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: iterative dynamic programming
// 
//      n: 6
//  delay: 2
// forget: 4
//                    . . v v
//                    . . v v
//                    . . v v
//                  . . v v
//              . . v v
//          . . v v
//        0 - - - - 5 - - - - 10
//                    i
// share: 0 0 0 1 2 2 4
//     C: 0 1 0 1 2 2 4

// 3ms 98.35% 39.4MB 96.35%
// iterative dynamic programming
// O(N) O(N)
// difficult
class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        // C[i]: pepole who found secret on i-th day
        long[] C = new long[n + 1];
        long mod = (long)1e9 + 7, share = 0, ans = 0;
        C[1] = 1;
        for (int i = 2; i <= n; ++i) {
            share = (share + C[Math.max(i - delay, 0)] -
                     C[Math.max(i - forget, 0)] + mod) % mod;
            C[i] = share;
        }
        for (int i = n - forget + 1; i <= n; ++i) {
            ans = (ans + C[i]) % mod;
        }        
        return (int)ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
