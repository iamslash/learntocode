// Copyright (C) 2022 by iamslash

import java.util.*;

// 222
// aaa
//  ab
//  ba
//   c
//


// Idea: Iterative dynamic programming
// 
// * Consider all cases
// 7      1
// p
// 77     2 
// pp
//  q
// 777    4
//   r
// p q
// ppp
//  qp
// 7777   8
//    s
// p  r
// pp q
//  q q
//   rp
// p qp
// pppp
//  qpp
//
// * Equation
// 7    = 1     
// 77   = 1 + 1
// 777  = 2 + 1 + 1
// 7777 = 4 + 2 + 1 + 1
// C[i] = C[i-1] + C[i-2] + C[i-3] + C[i-4]

// 45ms 88.89% 43MB 100.00%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int countTexts(String k) {
        int MOD = 1_000_000_007;
        int[] C = new int[]{1, 1, 1, 1, 1};
        int n = k.length();
        for (int i = n - 1; i >= 0; --i) {
            C[i % 5] = 0;
            int unit = k.charAt(i) == '7' || k.charAt(i) == '9' ? 4 : 3;
            int maxJ = Math.min(n, i + unit);
            for (int j = i; j < maxJ && k.charAt(i) == k.charAt(j); ++j) {
                C[i % 5] = (C[i % 5] + C[(j+1) % 5]) % MOD;
            }
        }
        return C[0];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
