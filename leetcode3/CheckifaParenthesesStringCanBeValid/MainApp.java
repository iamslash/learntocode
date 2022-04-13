// Copyright (C) 2022 by iamslash

import java.util.*;

// locked: 010100
//      s: ))()))
//         *)*)**

// 21ms 71.40% 43.7MB 82.95%
// greedy, back and forth
// O(N) O(N)
class Solution {
    public boolean canBeValid(String s, String locked) {
        if (s.length() % 2 != 0) {
            return false;
        }
        int wild = 0, left = 0, right = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (locked.charAt(i) == '0') {
                wild++;
            } else if (s.charAt(i) == '(') {
                left++;
            } else if (s.charAt(i) == ')') {
                right++;
            }
            if (wild + left - right < 0) {
                return false;
            }
        }
        wild = left = right = 0;
        for (int i = n-1; i >= 0; --i) {
            if (locked.charAt(i) == '0') {
                wild++;
            } else if (s.charAt(i) == '(') {
                left++;
            } else if (s.charAt(i) == ')') {
                right++;
            }
            if (wild + right - left < 0) {
                return false;
            }
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}

