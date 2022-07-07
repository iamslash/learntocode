// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 100.00% 42.6MB 100.00%
// two pointers
// O(N) O(1)
class Solution {
    public boolean makePalindrome(String s) {
        int n = s.length(), i = 0, j = n-1, diffCnt = 0;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                diffCnt++;
            }
            if (diffCnt > 2) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
