// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: greedy, hash map
//
// We have number of characters like this.
// - (evn) The number of even characters pairs: 4 (ex, aa aa bb bb)
// - (odd) The number of odd characters: 0 
// We have lengths of words descendingly to make palindrome.
// - (lens) 4 2 2
// We can maximum number of palindrome.
//   - odd -= lens[i] % 2
//     - if odd < 0, evn--; odd += 2
//   - evn -= lens[i] / 2
//     - if evn < 0, return i
// ex)
// - 4 (aa aa)
// - 2 (bb)
// - 2 (bb)

// 5ms 100.00% 45.2MB 25.00%
// greedy, hash map
// O(N) O(N)
class Solution {
    public int maxPalindromesAfterOperations(String[] words) {
        int n = words.length;
        int[] wordLens = new int[n];
        for (int i = 0; i < n; ++i) {
            wordLens[i] = words[i].length();
        }
        Arrays.sort(wordLens);

        int[] charCnts = new int[26];
        for (String word : words) {
            for (char c : word.toCharArray()) {
                charCnts[c - 'a']++;
            }
        }

        int evn = 0, odd = 0;
        for (int cnt : charCnts) {
            evn += cnt / 2;
            odd += cnt % 2;
        }

        for (int i = 0; i < n; ++i) {
            odd -= wordLens[i] % 2;
            if (odd < 0) {
                evn--;
                odd += 2;
            }
            evn -= wordLens[i] / 2;
            if (evn < 0) {
                return i;
            }
        }
        return n;
    }
}

// words: abbb ba aa
//  cnts: a b
//        4 4
//   evn: 0 
//   odd: 0

// words: aabb cc dd
//  cnts: a b c d
//        2 2 2 2
//          i
//  lens: 4 2 2
//   evn: 1
//   odd: 0

// words: aabe cc dd
//  cnts: a b c d e
//        2 1 2 2 1
//            i
//  lens: 4 2 2
//   evn: 0
//   odd: 2
