// Copyright (C) 2024 by iamslash

import java.util.*;

// ababa

// 4ms 71.43% 44.5MB 28.57%
// brute force
// O(N^2) O(1)
class Solution {
    private boolean isPrefixAndSuffix(String a, String b) {
        int n = a.length(), m = b.length();
        if (n > m) {
            return false;
        }
        String pfx = b.substring(0, n);
        String sfx = b.substring(m - n);
        return a.equals(pfx) && a.equals(sfx);
    }
    public int countPrefixSuffixPairs(String[] words) {
        int cnt = 0, n = words.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
