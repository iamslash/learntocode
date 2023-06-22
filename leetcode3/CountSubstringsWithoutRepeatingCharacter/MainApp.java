// Copyright (C) 2023 by iamslash

import java.util.*;

//   i
// baab
// j

// 39ms 100.00% 44.7MB 100.00%
// two pointers
// O(N) O(1)
class Solution {
    public int numberOfSpecialSubstrings(String s) {
        int[] freqs = new int[26];
        int n = s.length(), j = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            int iPos = s.charAt(i) - 'a';
            freqs[iPos]++;
            while (freqs[iPos] == 2) {
                freqs[s.charAt(j++) - 'a']--;
            }
            cnt += (i - j + 1);
        }
        return cnt;
    }
}
