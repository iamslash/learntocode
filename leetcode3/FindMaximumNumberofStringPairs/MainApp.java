// Copyright (C) 2023 by iamslash

import java.util.*;

// 3ms 33.33% 43.3MB 33.33%
// hash set
// O(N) O(N)
class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        Set<String> wordSet = new HashSet<>();
        int cnt = 0;
        for (String word : words) {
            String reversed = String.valueOf(new char[]{word.charAt(1), word.charAt(0)}); 
            if (wordSet.contains(reversed)) {                
                cnt++;
            }
            wordSet.add(word);
        }
        return cnt;
    }
}


// 2ms 66.67% 41MB 100.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        int cnt = 0, n = words.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].charAt(0) == words[j].charAt(1) &&
                    words[i].charAt(1) == words[j].charAt(0)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
