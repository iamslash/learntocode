// Copyright (C) 2022 by iamslash

import java.util.*;

// 450ms 11.63% 138MB 33.33%
// set, sort
// O(NlgN) O(N)
class Solution {
    public int wordCount(String[] startWords, String[] targetWords) {
        int n = startWords.length, cnt = 0;
        Set<String> srcWordSet = new HashSet<>();
        // Build srcWordSet
        for (String word : startWords) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            srcWordSet.add(new String(chars));
        }
        int m = targetWords.length;
        for (String word : targetWords) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            int tgtWordLen = chars.length;
            String tgtWord = String.valueOf(chars);
            for (int i = 0; i < tgtWordLen; ++i) {
                String cand = tgtWord.substring(0, i) + tgtWord.substring(i + 1);
                if (srcWordSet.contains(cand)) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
}

// Idea: bit manipulation
//
// No letter occurs more than once in any string of startWords or
// targetWords.

// 109ms 66.60% 111MB 45.25%
// bit manipulation, set
// O(N) O(N)
class Solution {
    public int wordCount(String[] startWords, String[] targetWords) {
        int cnt = 0;
        Set<Integer> srcSet = new HashSet<>();
        for (String word : startWords) {
            int bm = 0;
            for (char c : word.toCharArray()) {
                bm |= (1 << (c - 'a'));
            }
            srcSet.add(bm);
        }
        for (String word : targetWords) {
            int bm = 0;
            for (char c : word.toCharArray()) {
                bm |= (1 << (c - 'a'));
            }
            for (char c : word.toCharArray()) {
                int cand = bm - (1 << (c - 'a'));
                if (srcSet.contains(cand)) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
}
