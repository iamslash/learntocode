// Copyright (C) 2022 by iamslash

import java.util.*;

//        i
//   num: 4 4 4 9 4 7 1 3 7
//                i
// freqs: 1 3 4 7 9
//        1 1 4 2 1

// 22ms 84.85% 53.6MB 71.07%
// hash map
// O(N) O(N)
class Solution {
    public String largestPalindromic(String num) {
        int[] freqs = new int[10];
        for (char c : num.toCharArray()) {
            freqs[c - '0']++;
        }
        StringBuilder sbFirst = new StringBuilder();
        StringBuilder sbLast = new StringBuilder();
        int mid = -1;
        for (int a = 9; a >= 0; --a) {
            if (sbFirst.length() == 0 && a == 0) {
                continue;
            }
            while (freqs[a] > 1) {
                sbFirst.append((char)(a + '0'));
                sbLast.append((char)(a + '0'));
                freqs[a] -= 2;
            }
            if (freqs[a] == 1 && mid == -1) {
                mid = a;
            }            
        }
        if (sbFirst.length() == 0 && mid == -1) {
            return "0";
        }
        if (mid != -1) {
            sbFirst.append((char)(mid + '0'));
        }
        sbFirst.append(sbLast.reverse().toString());
        return sbFirst.toString();
    }
}


