// Copyright (C) 2023 by iamslash

import java.util.*;


//               i
// word: a a a a b b
//  prv: a a a a 
//  grp: 1 2 3 4 

// 2ms 97.87% 42.8MB 24.13%
// greedy
// O(N) O(1)
class Solution {
    public int addMinimum(String word) {
        int n = word.length(), grp = 0;
        char prv = 'z';
        for (char c : word.toCharArray()) {
            if (c <= prv) {
                grp++;
            }
            prv = c;
        }
        return grp * 3 - n;
    }
}
