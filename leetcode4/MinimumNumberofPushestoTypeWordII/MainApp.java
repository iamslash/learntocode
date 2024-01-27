// Copyright (C) 2024 by iamslash

import java.util.*;

// word: a b c d e
// cnts: a b c d e
//       1 1 1 1 1
//
// 

// Idea:
//
// word is consisted of lowercase English letters.
// Can remap distinct letters to number [2, 9] which is 8 elements.

// 8ms 91.50% 45.4MB 97.85%
// sort
// O(NlgN) O(1)
class Solution {
    public int minimumPushes(String word) {
        int[] cnts = new int[26];
        for (char c : word.toCharArray()) {
            cnts[c - 'a']++;
        }
        Arrays.sort(cnts);

        int idx = 1, sum = 0, cnt = 1;
        for (int i = 25; i >= 0; --i) {
            if (idx <= 8) {
                idx++;
            } else {
                idx = 2;
                cnt++;
            }
            sum += cnts[i] * cnt;
        }
        
        return sum;
    }
}
