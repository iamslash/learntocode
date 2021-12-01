// Copyright (C) 2021 by iamslash

import java.util.*;

// s: a b c b a
//    .
//    a
//    b ab
//    c bc abc
//    b cb bcb abcb
//    a ba cba bcba abcba
// freqs: a b c 
//        1 2 1

// brute force
// O(N) O(1)
class Solution {
    public long numberOfSubstrings(String s) {
        int ans = 0;
        int[] freqs = new int[26];
        for (char c : s.toCharArray()) {
            freqs[c-'a']++;
        }
        for (int i = 0; i < freqs.length; ++i) {
            int cnt = freqs[i];
            ans += cnt * (cnt + 1) / 2;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
