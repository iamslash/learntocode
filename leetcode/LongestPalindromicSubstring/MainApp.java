// Copyright (C) 2022 by iamslash

import java.util.*;

//          i
//      s: babad
// oddPal: b
// evnPal: 

// 25ms 78.02% 39MB 82.47%
// brute force
// O(N) O(1)
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int maxIdx = 0, maxLen = 1;
        for (int i = 0; i < n; ++i) {
            // Check odd palindrome
            int r = 1;
            while (i-r >= 0 && i+r < n &&
                   s.charAt(i-r) == s.charAt(i+r)) {
                int curLen = 2 * r + 1;
                if (maxLen < curLen) {
                    maxLen = curLen;
                    maxIdx = i-r;
                }
                ++r;
            }
            // Check even palindrome
            r = 1;
            while (i-r+1 >= 0 && i+r < n &&
                   s.charAt(i-r+1) == s.charAt(i+r)) {
                int curLen = 2 * r;
                if (maxLen < curLen) {
                    maxLen = curLen;
                    maxIdx = i-r+1;
                }
                ++r;
            }
        }
        return s.substring(maxIdx, maxIdx+maxLen);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
