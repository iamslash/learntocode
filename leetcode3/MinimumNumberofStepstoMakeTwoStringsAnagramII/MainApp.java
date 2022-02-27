// Copyright (C) 2022 by iamslash

import java.util.*;

// 32ms 50.00% 68.4MB 75.00%
// hash map
// O(N) O(1)
class Solution {
    public int minSteps(String s, String t) {
        int[] sFreqs = new int[26];
        int[] tFreqs = new int[26];
        for (char c : s.toCharArray()) {
            sFreqs[c-'a']++;
        }
        for (char c : t.toCharArray()) {
            tFreqs[c-'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += Math.abs(sFreqs[i] - tFreqs[i]);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
