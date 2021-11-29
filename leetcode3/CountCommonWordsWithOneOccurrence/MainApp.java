// Copyright (C) 2021 by iamslash

import java.util.*;

// 5ms 100.00% 39MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    public int countWords(String[] words1, String[] words2) {
        int ans = 0;
        Map<String, Integer> words1FreqMap = new HashMap<>();
        Map<String, Integer> words2FreqMap = new HashMap<>();
        for (String s : words1) {
            words1FreqMap.put(s, words1FreqMap.getOrDefault(s, 0) + 1);
        }
        for (String s : words2) {
            words2FreqMap.put(s, words2FreqMap.getOrDefault(s, 0) + 1);
        }
        for (String s : words1FreqMap.keySet()) {
            int cnt = words1FreqMap.get(s);
            if (cnt > 1) {
                continue;
            }
            if (words2FreqMap.containsKey(s) && words2FreqMap.get(s) == 1) {
                ans++;
            }
        }
        return ans;
    }
}
