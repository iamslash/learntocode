// Copyright (C) 2022 by iamslash

import java.util.*;

// s: 111000
//    111000111000

// Idea: sliding window
//
// Attach s to s.
// Slide the window, add new one, sub old one
// Save the min alternatives.
//
// ex)
// s:1100
//   11001100
//   ----
//    ----
//     ----
//      ----
//       ----

// 46ms 43.67% 50.1MB 68.12%
// sliding window
// O(N) O(1)
class Solution {
    public int minFlips(String s) {
        int minCnt = 100_000, cnt0 = 0, cnt1 = 0, n = s.length();
        for (int i = 0; i < 2 * n; ++i) {
            if (s.charAt(i % n) - '0' != i % 2) {
                cnt0++;
            } else {
                cnt1++;
            }
            // sub previous added count and
            // save min alternatives
            if (i >= n) {
                if (s.charAt((i - n) % n) - '0' != (i - n) % 2) {
                    cnt0--;
                } else {
                    cnt1--;
                }
                minCnt = Math.min(minCnt, Math.min(cnt0, cnt1));
            }
        }
        return minCnt;                                
    }
}
