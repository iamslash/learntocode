// Copyright (C) 2022 by iamslash

import java.util.*;

//    i
// s: a b a c a b a
//    j

// 27ms 40.89% 54.2MB 70.12%
// two pointers
// O(N) O(1)
class Solution {
    public int longestContinuousSubstring(String s) {
        int i = 0, n = s.length(), maxLen = 0;
        for (int j = 0; j < n; ++j) {
            int diff = j - i;
            if (s.charAt(i) + diff != s.charAt(j)) {
                i = j;
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }
        return maxLen;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
