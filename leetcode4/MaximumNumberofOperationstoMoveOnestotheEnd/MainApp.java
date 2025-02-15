// Copyright (C) 2025 by iamslash

import java.util.*;

//      i
// s: 1001101
//    0011101
//    0001111

//         i
// s: 00111
//
//

// 7ms 81.68% 45.34MB 75.57%
// linear traversal
// O(N) O(1)
class Solution {
    public int maxOperations(String s) {
        int opsCnt = 0, n = s.length(), oneCnt = 0;

        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == '1') {
                oneCnt++;
            } else if (i > 0 && s.charAt(i - 1) == '1' &&
                       c == '0') {
                opsCnt += oneCnt;
            }
        }

        return opsCnt;
    }
}
