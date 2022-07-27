// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 40.5MB 75.00%
// hash map
// O(N) O(1)
class Solution {
    public char repeatedCharacter(String s) {
        int[] freqs = new int[26];
        for (char c : s.toCharArray()) {
            if (++freqs[c-'a'] > 1) {
                return c;
            }
        }
        return 'a';
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
