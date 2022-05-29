// Copyright (C) 2022 by iamslash

import java.util.*;

//            i
// num: 1 2 1 0
//      

// 1ms 100.00% 43MB 14.29%
// hash map
// O(1) O(1)
class Solution {
    public boolean digitCount(String num) {
        int n = num.length();
        int[] cnts = new int[10];
        for (char c : num.toCharArray()) {
            cnts[c-'0']++;
        }
        for (int i = 0; i < n; ++i) {
            if (cnts[i] != num.charAt(i)-'0') {
                return false;
            }
        }
        return true;
    }
}
