// Copyright (C) 2022 by iamslash

import java.util.*;

//
// abcdefghijkl
//          i
// abcdedfhi


// Idea:
// allocate less count for less frequent character
//
// 8ms 100.00% 47.4MB 100.00%
// sort
// O(N) O(1)
class Solution {
    public int minimumKeypresses(String s) {
        int[] freqs = new int[26];
        for (char c : s.toCharArray()) {
            freqs[c-'a']++;
        }
        Arrays.sort(freqs);
        int ord = 0, cnt = 0;
        for (int i = 25; i >= 0; --i) {
            if (freqs[i] > 0) {
                if (ord < 9) {
                    cnt += freqs[i];
                } else if (ord < 18) {
                    cnt += freqs[i] * 2;
                } else {
                    cnt += freqs[i] * 3;
                }
                ord++;
            }
        }
        return cnt;
    }
}
