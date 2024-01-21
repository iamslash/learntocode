// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea:
//
// word is consisted of distinct lowercase English letters.
// Can remap distinct letters to number [2, 9] which is 8 elements.

// 0ms 100.00% 41.6MB 100.00%
// math
// O(N) O(1)
class Solution {
    public int minimumPushes(String word) {
        int n = word.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i / 8 + 1;
        }
        return ans;
    }
}
