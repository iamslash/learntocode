// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.1MB 100.00%
// brute force
// O(1) O(1)
class Solution {
    public String findLatestTime(String s) {
        char[] chrs = s.toCharArray();
        if (chrs[0] == '?') {
            if (chrs[1] == '?' || chrs[1] < '2') {
                chrs[0] = '1';
            } else {
                chrs[0] = '0';
            }
        }
        if (chrs[1] == '?') {
            if (chrs[0] == '1') {
                chrs[1] = '1';
            } else {
                chrs[1] = '9';
            }
        }
        if (chrs[3] == '?') {
            chrs[3] = '5';
        }
        if (chrs[4] == '?') {
            chrs[4] = '9';
        }
        return String.valueOf(chrs);
    }
}
