// Copyright (C) 2022 by iamslash

import java.util.*;

//           s: cczazcc
// repeatLimit: 3
//                   i
//              zzcccca
//         

// hash map
// O(N) O(N)
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        char[] freqs = new char[26];
        for (char c : s.toCharArray()) {
            freqs[c-'a']++;
        }
        int i = 25;
        StringBuilder ans = new StringBuilder();
        while (i >= 0) {
            if (i < 25 && freqs[i+1] > 0) {
                i++;
            }
            if (freqs[i] > 0) {
                int len = Math.min(freqs[i], repeatLimit);
                for (int j = 0; j < len; ++j) {
                    ans.append((char)('a'+i));
                }
                freqs[i] -= len;
            }
            i--;
        }
        return ans.toString();
    }
}
