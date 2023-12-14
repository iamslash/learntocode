// Copyright (C) 2023 by iamslash

import java.util.*;

//                 i
// word: a b d d e z
//          
//  cnt: 2

// 1ms 100.00% 40.9MB 94.46%
// greedy
// O(N) O(1)
class Solution {
    public int removeAlmostEqualCharacters(String word) {
        int cnt = 0, n = word.length();
        for (int i = 1; i + cnt < n; ++i) {
            int diff = Math.abs(word.charAt(i + cnt) - word.charAt(i + cnt - 1));
            if (diff < 2) {
                cnt++;
            }
        }
        return cnt;
    }
}
