// Copyright (C) 2023 by iamslash

import java.util.*;

// 30ms 20.00% 45.1MB 40.00%
// brute force
// O(N) O(N)
class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            String[] strs = word.split(String.format("[%c]", separator));
            for (String str : strs) {
                if (!str.isEmpty()) {
                    ans.add(str);
                }
            }
        }
        return ans;
    }
}
