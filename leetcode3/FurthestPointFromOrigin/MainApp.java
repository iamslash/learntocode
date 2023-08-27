// Copyright (C) 2023 by iamslash

import java.util.*;

// L_RL__R
// LLRLLLR
// LRRLRRR

// _R__LL_
// LRLLLLL

// 1ms 100.00% 41.6MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int n = moves.length(), lCnt = 0, rCnt = 0, uCnt = 0;
        for (char c : moves.toCharArray()) {
            if (c == 'L') {
                lCnt++;
            } else if (c == 'R') {
                rCnt++;
            } else {
                uCnt++;
            }
        }
        return Math.abs(lCnt - rCnt) + uCnt;
    }
}
