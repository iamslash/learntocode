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

// nCr = n! / (r! * (n-r)!)
//
// nC2 = n * (n - 1) / 2

// 3ms 100.00% 39.5MB 86.01%
// math
// O(N) O(1)
class Solution {
    public long numberOfSubstrings(String s) {
        long ans = s.length();
        long[] freqs = new long[26];
        for (char c : s.toCharArray()) {
            freqs[c-'a']++;
        }
        for (int i = 0; i < freqs.length; ++i) {
            ans +=  freqs[i] * (freqs[i] - 1) / 2;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
