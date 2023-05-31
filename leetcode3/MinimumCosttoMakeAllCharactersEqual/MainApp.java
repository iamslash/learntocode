// Copyright (C) 2023 by iamslash

import java.util.*;

// s: 0 0 1 1
//    1 1 1 1    2
//

// s: 0 1 0 1 0 1    1
//    1 1 0 1 0 1    2 
//    0 0 0 1 0 1    3
//    1 1 1 1 0 1    2
//    1 1 1 1 1 0    1
//    1 1 1 1 1 1

// s: 0 0 0
//      i
// s: 0 1 1
//        i
// s: 0 1 0
//        i
// s: 0 0 1
//

//          i
// s: 0 1 0 1    1
//


// Idea: greedy
//
// Let's think from the simple one.
//
// s: 0 0 0
//    i
// s: 0 1 1    cost: 1
//      i
// s: 0 1 0    cost: 1 + 1
//        i
// s: 0 0 1    cost: 1
//
// When s[i-1] != s[i], the minimum cost is
//   min(i, n - i)
// i means replace s[0..i) with s[i].
// n - i means replace s[i..n) with s[i-1].
//
// The cost is same when we consider forward or backward.
//
//            . . .
// s: 0 0 0 0 1 0 1    3 2 1
//          . . .
// s: 0 0 0 0 1 0 1    1 2 3

// 12ms 72.05% 44.7MB 38.76%
// greedy
// O(N) O(1)
class Solution {
    public long minimumCost(String s) {
        int n = s.length();
        long ans = 0;
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i - 1) != s.charAt(i)) {
                ans += Math.min(i, n - i);
            }
        }        
        return ans;
    }
}
