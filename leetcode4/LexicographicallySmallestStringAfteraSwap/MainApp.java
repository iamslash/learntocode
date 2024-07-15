// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.6MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public String getSmallestString(String s) {
        int n = s.length();
        char[] chrs = s.toCharArray();
        
        for (int i = 0; i < n - 1; ++i) {
            int mod1 = (chrs[i] - '0') % 2;
            int mod2 = (chrs[i + 1] - '0') % 2;
            if (mod1 == mod2 && chrs[i] > chrs[i + 1]) {
                char tmp = chrs[i];
                chrs[i] = chrs[i + 1];
                chrs[i + 1] = tmp;
                break;
            }
        }

        return new String(chrs);
    }
}
