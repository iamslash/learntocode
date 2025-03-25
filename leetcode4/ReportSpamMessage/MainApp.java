// Copyright (C) 2025 by iamslash

import java.util.*;

// 53ms 49.03% 73.65MB 72.30%
// hash set
// O(N) O(N)
class Solution {
    public boolean reportSpam(String[] message,
                              String[] bannedWords) {
        //
        int n = message.length, m = bannedWords.length;
        Set<String> wordSet = new HashSet<>();

        for (String word : bannedWords) {
            wordSet.add(word);
        }

        int cnt = 0;
        for (String word : message) {
            if (wordSet.contains(word)) {
                cnt++;
            }
            if (cnt >= 2) {
                return true;
            }
        }

        return false;
    }
}
