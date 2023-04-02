// Copyright (C) 2023 by iamslash

import java.util.*;

//    i
//     j
// s: 01000111
//      k

// 2ms 100.00% 42.4MB 71.43%
// two pointers
// O(N) O(1)
class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int i = 0, j = 0, k = 0, n = s.length(), ans = 0;
        while (i < n) {
            while (i < n && s.charAt(i) == '1') {
                i++;
            }
            j = i;
            while (j < n && s.charAt(j) == '0') {
                j++;
            }
            k = j;
            while (k < n && s.charAt(k) == '1') {
                k++;
            }
            ans = Math.max(ans, 2 * Math.min(j - i, k - j));
            i = k;
        }
        return ans;
    }
}
