// Copyright (C) 2024 by iamslash

import java.util.*;

//  minLen: 3
//            i
//   words: cat dog rat cats dogcatsdog catsdogcats ratcatdogcat hippopotamuses
// wordSet: 
//     ans: 
//

// Time Limit Exceeded
// sort
// O(NlgN) + O(N * 2^N)
// O(NK) + O(L)
// N: the number of words.
// L: the length of the word.
// K: the average length of the words.
class Solution {
    private boolean concatenated(Set<String> wordSet, int minLen, String word) {
        // base
        if (wordSet.contains(word)) {
            return true;
        }

        // recursion
        for (int i = minLen; i <= word.length() - minLen; ++i) {
            if (wordSet.contains(word.substring(0, i)) &&
                concatenated(wordSet, minLen, word.substring(i))) {
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
            if (word.length() >= minLen * 2 &&
                concatenated(wordSet, minLen, word)) {
                ans.add(word);
            }
            wordSet.add(word);
        }

        return ans;
    }
}

//  minLen: 3
//                                     i
//   words: cat dog rat cats dogcatsdog catsdogcats ratcatdogcat hippopotamuses
//                           j
//       C:                  tfftffttfft
// wordSet: cat dog rat cats
//       
//     ans: 
//

// 64ms 55.22% 48.6MB 75.37%
// iterative dynamic programming
// O(NlgN) + (NM^2)
// O(NK) + O(M)
// - N: number of words
// - M: the maximum word length
// K: the average length of the words.
class Solution {

    private boolean concatenated(Set<String> wordSet, int minLen, String word) {
        // base
        if (wordSet.isEmpty()) {
            return false;
        }

        int n = word.length();
        // C[i]: substring whose length is i is concatenated?
        boolean[] C = new boolean[n + 1];
        C[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (C[j] && wordSet.contains(word.substring(j, i))) {
                    C[i] = true;
                    break;
                }
            }
        }
        
        return C[n];
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
