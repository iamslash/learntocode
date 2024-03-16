// Copyright (C) 2024 by iamslash

import java.util.*;

//        C: fffffffft
//        s: leetcode
//               i
// wordList: leet code
//

// 3ms 84.65% 41.9MB 82.92%
// iterative dynamic programming
// O(SW) O(S)
class Solution {
    public boolean wordBreak(String s, List<String> wordList) {
        int n = s.length();
        boolean[] C = new boolean[n + 1];
        C[n] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (String word : wordList) {
                int m = word.length();
                if (i + m <= n &&
                    C[i + m] &&
                    s.substring(i, i + m).equals(word)) {
                    C[i] = true;
                    break;
                }
            }
        }

        return C[0];
    }
}
