// Copyright (C) 2024 by iamslash

import java.util.*;

// 2ms 98.92% 43.5MB 87.87%
// two pointers
// O(N) O(1)
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] cnts = new int[256];
        int i = 0, j = 0, maxLen = 0, n = s.length();

        while (j < n) {
            cnts[s.charAt(j)]++;

            while (i < j && cnts[s.charAt(j)] > 1) {
                cnts[s.charAt(i)] = --cnts[s.charAt(i)];
                i++;
            }

            maxLen = Math.max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
}
