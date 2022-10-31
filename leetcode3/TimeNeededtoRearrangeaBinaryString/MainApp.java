// Copyright (C) 2022 by iamslash

import java.util.*;

//    f
// s: 0 1 1 0 1 0 1
//    7 - 3 = 4
//    4 - 0 = 4

//                c
//   s: 0 0 1 0 1 1
// zro: 1 2 2 3 3 3
// ans: 0 0 2 2 3 4
//
//   s: 0 0 1 0 1 1
//      0 1 0 1 0 1
//      1 0 1 0 1 0
//      1 1 0 1 0 0
//      1 1 1 0 0 0

// 10ms 74.86% 42.1MB 71.61%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int secondsToRemoveOccurrences(String s) {
        int zeroCnt = 0, ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            zeroCnt += c == '0' ? 1 : 0;
            if (c == '1' && zeroCnt > 0) {
                ans = Math.max(ans + 1, zeroCnt);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
