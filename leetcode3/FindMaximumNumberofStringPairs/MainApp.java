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
