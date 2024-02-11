// Copyright (C) 2024 by iamslash

import java.util.*;

//
//              i
//     s: barfoofoobar
//              j
// words: foo bar
//        F   B

//     s: bcabbcaa bbccacacbabccacaababcbb
// words: c b c a a a b c

// Idea: hash
//
// The length of concatenated substring
// should be length of strings in words.

// Wrong Answer:
// Input:
// "bcabbcaabbccacacbabccacaababcbb"
// ["c","b","a","c","a","a","a","b","c"]
// Output:
// [0,1,2,6,16,17,18,19,20,22]
// Expected:
// [6,16,17,18,19,20]
//
// hash
// O(N) O(N)
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans = new ArrayList<>();

        int n = words.length, m = words[0].length();
        long wordsHash = 0;
        for (String word : words) {
            wordsHash += word.hashCode();
        }

        for (int i = 0; i + m * n <= s.length(); ++i) {
            long sumHash = wordsHash;
            for (int j = 0; j < n; ++j) {
                int beg = i + j * m, end = beg + m;
                sumHash -= s.substring(beg, end).hashCode();
            }
            if (sumHash == 0) {
                ans.add(i);
            }
        }

        return ans;
    }
}

// 2420ms 18.32% 46.1MB 19.63%
// hash map
// O(N^2) O(N)
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans = new ArrayList<>();
        Map<String, Integer> wordCntMap = new HashMap<>();
        int n = words.length, m = words[0].length(), wndLen = m * n;

        for (String word : words) {
            wordCntMap.put(word, wordCntMap.getOrDefault(word, 0) + 1);
        }

        for (int i = 0; i + wndLen <= s.length(); i++) {
            Map<String, Integer> seenMap = new HashMap<>();
            int j = 0;
            while (j < n) {
                int beg = i + j * m, end = beg + m;
                String word = s.substring(beg, end);
                if (wordCntMap.containsKey(word)) {
                    seenMap.put(word, seenMap.getOrDefault(word, 0) + 1);
                    if (seenMap.get(word) > wordCntMap.get(word)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == n) {
                ans.add(i);
            }
        }

        return ans;
    }
}
