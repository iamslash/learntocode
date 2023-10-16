// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 44MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public List<String> getWordsInLongestSubsequence(int n, String[] words, int[] groups) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || groups[i-1] != groups[i]) {
                ans.add(words[i]);
            }
        }
        return ans;
    }
}
