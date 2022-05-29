// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 33.33% 42MB 33.33%
// hash map
// O(N) O(1)
class Solution {
    public int rearrangeCharacters(String s, String target) {
        int[] srcFreqs = new int[128];
        int[] tgtFreqs = new int[128];
        for (char c : s.toCharArray()) {
            srcFreqs[c-'a']++;
        }
        for (char c : target.toCharArray()) {
            tgtFreqs[c-'a']++;
        }
        int cnt = Integer.MAX_VALUE;
        for (int i = 0; i < 128; ++i) {
            if (tgtFreqs[i] > 0) {
                // System.out.printf("%c %d %d\n", 'a'+i, srcFreqs[i], tgtFreqs[i]);
                cnt = Math.min(cnt, srcFreqs[i] / tgtFreqs[i]);
            }
        }
        return cnt;
    }
}
