// Copyright (C) 2022 by iamslash

import java.util.*;

// p: a c
// s: a b d c d b c

// Idea: greedy
//
// Count pattern[0] and pattern[1] in s.
// When pattern[1] happens in s, update ans.
// The max way is that pattern[0] is first or pattern[1] is last.

// 28ms 48.04% 53.8MB 64.63%
// greedy algorithm
// O(N) O(1)
class Solution {
    public long maximumSubsequenceCount(String s, String pattern) {
        long ans = 0, cnt1 = 0, cnt2 = 0;
        for (char c : s.toCharArray()) {
            if (c == pattern.charAt(1)) {
                ans += cnt1;
                cnt2++;
            }
            if (c == pattern.charAt(0)) {
                cnt1++;
            }
        }
        return ans + Math.max(cnt1, cnt2);
    }
}
