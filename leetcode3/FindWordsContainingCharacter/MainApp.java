// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 43.8MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        int n = words.length;
        List<Integer> idxList = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            String word = words[i];
            for (char c : word.toCharArray()) {
                if (c == x) {
                    idxList.add(i);
                    break;
                }
            }
        }
        return idxList;
    }
}
