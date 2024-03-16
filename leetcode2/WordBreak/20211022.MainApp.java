// Copyright (C) 2021 by iamslash

import java.util.*;

//  
//        s: leetcode
// wordDict: leet code
//        C: fffffffft

// 3ms 88.90% 39.2MB 68.50%
// iterative dynamic programming
// O(SW) O(S)
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] C = new boolean[n + 1];
        C[n] = true;
        for (int i = n-1; i >= 0; --i) {
            for (String word : wordDict) {
                int m = word.length();
                if (i+m <= n &&
                    C[i+m] &&
                    s.substring(i, i+m).equals(word)) {
                    C[i] = true;
                    break;
                }
            }
        }
        return C[0];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
