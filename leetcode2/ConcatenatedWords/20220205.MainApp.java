// Copyright (C) 2022 by iamslash

import java.util.*;

//                           i
//   words: cat dog rat cats dogcatsdog catsdogcats ratcatdogcat hippopotamuses
// wordSet: 
//     ans: cat dog rat cats
//

// Time Limit Exceeded
// DFS
// O(??) O(??)
class Solution {
    private boolean concatenated(Set<String> wordSet, int minLen, String s) {
        // base
        if (wordSet.contains(s)) {
            return true;
        }
        // recursion
        for (int i = minLen; i <= s.length() - minLen; ++i) {
            if (wordSet.contains(s.substring(0, i)) &&
                concatenated(wordSet, minLen, s.substring(i))) {
                return true;
            }
        }
        return false;
    }
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        Set<String> wordSet = new HashSet<>();
        int minLen = Math.max(1, words[0].length());
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            if (word.length() >= minLen*2 && concatenated(wordSet, minLen, word)) {
                ans.add(word);
            }
            wordSet.add(word);
        }
        return ans;
    }
}

//  i
// dogcatsdog
// j

// 1002ms 59.38% 46.8MB 75.30%
// dynamic programming
// O(N*S^3) O(NS)
//   N: count of words
//   S: avg length of each word
class Solution {
    private boolean concatenated(Set<String> wordSet, int minLen, String s) {
        // base
        if (wordSet.isEmpty()) {
            return false;
        }
        // C[i]: substring whose length is i is concatenated?
        boolean[] C = new boolean[s.length() + 1];
        C[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (C[j] && wordSet.contains(s.substring(j, i))) {
                    C[i] = true;
                    break;
                }
            }
        }
        return C[s.length()];
    }
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        Set<String> wordSet = new HashSet<>();
        int minLen = Math.max(1, words[0].length());
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            if (word.length() >= minLen*2 && concatenated(wordSet, minLen, word)) {
                ans.add(word);
            }
            wordSet.add(word);
        }
        return ans;
    }
}

// public class MainApp {
//   public static void main(String[] args) {
//       String[] words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
//       Arrays.sort(words, (a, b) -> a.length() - b.length());
//       for (String word : words) {
//           System.out.println(word);
//       }             
//   }
// }
