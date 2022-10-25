// Copyright (C) 2022 by iamslash

import java.util.*;

//                      i   
//            I I D D D I
//     buf:       3 4 5 6
//     ans:   1 2 6 5 4 3

// 1ms 92.17% 42MB 55.84%
// brute force
// O(N) O(N)
class Solution {
    public String smallestNumber(String s) {
        StringBuilder ans = new StringBuilder();
        StringBuilder buf = new StringBuilder();
        int n = s.length();
        for (int i = 0; i <= n; ++i) {
            buf.append((char)('1' + i));
            if (i == n || s.charAt(i) == 'I') {
                ans.append(buf.reverse());
                buf = new StringBuilder();
            }
        }
        return ans.toString();
    }
}
