// Copyright (C) 2024 by iamslash

import java.util.*;

//    i
// s: a a a a
//            j
//            k
//    x

// 48ms 91.86% 178.7MB 5.03%
// sliding window
// O(N) O(N)
// difficult
class Solution {
    public int maximumLength(String s) {
        int sLen = s.length();
        char[] chrs = s.toCharArray();
        int[][] cntMap = new int[26][sLen];
        int ans = -1, n = chrs.length, i = 0;
        while (i < n) {
            int j = i;

            while (j < n && chrs[j] == chrs[i]) {
                j++;
            }

            int idx = 0;
            for (int k = j - i; k > 0; k--, idx++) {
                cntMap[chrs[i] - 'a'][idx] += k;
                if (cntMap[chrs[i] - 'a'][idx] > 2)
                    ans = Math.max(ans, idx + 1);
            }

            i = j; //jump to first different 
        }
        return ans;
    }     
}
