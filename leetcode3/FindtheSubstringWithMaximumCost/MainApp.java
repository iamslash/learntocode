// Copyright (C) 2023 by iamslash

import java.util.*;

// scores: a d
//         9 -
//         i
//      s: a d a a
// locMax: 9 8 
// glbMax: 9 9

// 6ms 95.07% 43MB 88.08%
// kadane
// O(N) O(1)
class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int locMax = 0, glbMax = 0;
        int[] scores = new int[26];
        for (int i = 0; i < 26; ++i) {
            scores[i] = i + 1;
        }
        for (int i = 0; i < chars.length(); ++i) {
            scores[chars.charAt(i) - 'a'] = vals[i];
        }
        for (char c : s.toCharArray()) {
            locMax = Math.max(0, locMax + scores[c - 'a']);
            glbMax = Math.max(glbMax, locMax);
        }
        return glbMax;
    }
}
