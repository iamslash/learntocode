// Copyright (C) 2021 by iamslash

import java.util.*;

//         i
//      s: cbaebabacd
//      p: abc
// sFreqs: a
//         
// pFreqs: a
//         1

// 5ms 97.74% 40.1MB 66.03%
// sliding window
// O(MN) O(N)
// M: length of string s
// N: length of string p
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        int m = s.length(), n = p.length();
        int[] sFreqs = new int[26];
        int[] pFreqs = new int[26];
        if (m < n) {
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            sFreqs[s.charAt(i)-'a']++;
            pFreqs[p.charAt(i)-'a']++;
        }
        if (Arrays.equals(sFreqs, pFreqs)) {
            ans.add(0);
        }
        for (int i = n; i < m; ++i) {
            sFreqs[s.charAt(i)-'a']++;
            sFreqs[s.charAt(i-n)-'a']--;
            if (Arrays.equals(sFreqs, pFreqs)) {
                ans.add(i-n+1);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
