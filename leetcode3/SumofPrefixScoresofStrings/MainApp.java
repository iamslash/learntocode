// Copyright (C) 2023 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // hash map
// // O(WN) O(WN)
// class Solution {
//     public int[] sumPrefixScores(String[] words) {
//         int n = words.length;
//         Map<String, Integer> cntMap = new HashMap<>();
//         for (String word : words) {
//             StringBuilder sb = new StringBuilder();
//             for (char c : word.toCharArray()) {
//                 sb.append(c);
//                 String key = sb.toString();
//                 cntMap.put(key, cntMap.getOrDefault(key, 0) + 1);
//             }
//         }
//         int[] ans = new int[n];
//         for (int i = 0; i < n; ++i) {
//             String word = words[i];
//             StringBuilder sb = new StringBuilder();
//             for (char c : word.toCharArray()) {
//                 sb.append(c);
//                 String key = sb.toString();
//                 ans[i] += cntMap.get(key);
//             }
//         }
//         return ans;
//     }
// }

// 622ms 46.09% 215.4MB 64.61%
// trie
// O(WN) O(WN)
class TrieNode {
    TrieNode[] nexts = new TrieNode[26];
    int cnt = 0;
}
class Solution {
    public int[] sumPrefixScores(String[] words) {
        TrieNode trieRoot = new TrieNode();
        // Build trie
        for (String word : words) {
            TrieNode u = trieRoot;
            for (int i = 0; i < word.length(); ++i) {
                int pos = word.charAt(i) - 'a';
                if (u.nexts[pos] == null) {
                    u.nexts[pos] = new TrieNode();
                }
                u.nexts[pos].cnt++;
                u = u.nexts[pos];
            }
        }
        // Get count from trie
        int n = words.length;
        int[] ans = new int[n];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            String word = words[i];
            TrieNode u = trieRoot;
            for (int j = 0; j < word.length(); ++j) {
                int pos = word.charAt(j) - 'a';
                ans[i] += u.nexts[pos].cnt;
                u = u.nexts[pos];
            }
        }
        return ans;
    }
}
