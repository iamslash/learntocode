// Copyright (C) 2023 by iamslash

import java.util.*;

//     
//   s: 1001
// ans: 2
//     
//   s: 0001
// ans: 1
//     
//   s: 0000
// ans: 0
//     
//   s: 1011
// ans: 1
//     
//   s: 1101
// ans: 1


// Idea: greedy
//
// s is even.
// s is divided even substring.
//
// 3ms 99.61% 43MB 98.88%
// greedy
// O(N) O(1)
class Solution {
    public int minChanges(String s) {
        int cnt = 0, n = s.length();;
        for (int i = 0; i < n; i += 2) {
            if (s.charAt(i) != s.charAt(i+1)) {
                cnt++;
            }
        }
        return cnt;
    }
}
