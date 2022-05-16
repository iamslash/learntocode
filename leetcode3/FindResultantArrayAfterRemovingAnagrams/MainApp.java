// Copyright (C) 2022 by iamslash

import java.util.*;

// 6ms 64.82% 45.4MB 71.32%
// sort
// O(NlgN) O(N)
class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> ans = new ArrayList<>();
        String prvWord = "";
        for (String word : words) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String curWord = String.valueOf(chars);
            if (prvWord.isEmpty() || !curWord.equals(prvWord)) {
                ans.add(word);
            }
            prvWord = curWord;
        }
        return ans;
    }
}
