// Copyright (C) 2022 by iamslash

import java.util.*;

// s: a a b b
//    a b b a

//        i
// s: l e t e l t
//              j
//    l e e l

// 18ms 65.58% 42.5MB 71.70%
// greedy algorithm
// O(N) O(N)
class Solution {
    public int minMovesToMakePalindrome(String s) {
        int ans = 0;
        while (!s.isEmpty()) {
            int i = s.indexOf(s.charAt(s.length() - 1));
            if (i == s.length() - 1) {
                ans += (i / 2);
            } else {
                ans += i;
                // Remove i-th character
                s = s.substring(0, i) + s.substring(i + 1);
            }
            // Remove j-th character
            s = s.substring(0, s.length() - 1);            
        }
        return ans;
    }
}
