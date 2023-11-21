// Copyright (C) 2023 by iamslash

import java.util.*;


//         i
//      s: 101010
// locCnt: 3
// glbCnt: 6

//    i
// s: 100

// Idea:
//
// The moving count of 1 is same with the moving count of 0.
// Let's consider just 1.
//
// Increase `cnt` when traverse 1.
//    i
// s: 10101
//
// Add `cnt` to `ans` when traverse 0.
//       i
// s: 11101
//
// 7ms 99.81% 44.7MB 48.44%
// greedy
// O(N) O(1)
class Solution {
    public long minimumSteps(String s) {
        long glbCnt = 0, locCnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                locCnt++;
            } else {
                glbCnt += locCnt;
            }
        }
        return glbCnt;
    }
}
