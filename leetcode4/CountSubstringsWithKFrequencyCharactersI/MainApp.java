// Copyright (C) 2025 by iamslash

import java.util.*;

//   k: 2
//       i 
//   s: abacb
//        j
// cnt:

//   k: 1
//       i 
//   s: abcde
//      j
// cnt:


// Idea: sliding window
// 
// Substring cnts = (n + 1) * n / 2.
// Find invalid substring each character appears
// at most k - 1.
// The answer is all substrings - invalid substrings
//
// Example)
//   k: 2
//       i 
//   s: abacb
//         j
// cnt: 0
//
// j: 0
// invalid substrings: a
// cnt: 15 - 1 = 14
//
// j: 1
// invalid substrings: ab, b
// cnt: 14 - 2 = 12
//
// j: 2
// invalid substrings: ba, a
// cnt: 12 - 2 = 10
//
// j: 3
// invalid substrings: bac, ac, c
// cnt: 10 - 3 = 7
//
// j: 4
// invalid substrings: acb, cb, b
// cnt: 7 - 3 = 4
//
// The answer is 4
//
// 1ms 100.00% 41.81MB 100.00%
// slding window
// O(N) O(N)
class Solution {
    public int numberOfSubstrings(String s, int k) {
        int n = s.length(), cnt = (n + 1) * n / 2;
        int[] freqs = new int[26];

        for (int i = 0, j = 0; j < n; ++j) {
            char c = s.charAt(j);
            int pos = c - 'a';
            freqs[pos]++;
            
            while (freqs[pos] >= k) {
                char left = s.charAt(i);
                freqs[left - 'a']--;
                i++;
            }

            cnt -= j - i + 1;
        }

        return cnt;        
    }
}
