// Copyright (C) 2023 by iamslash

import java.util.*;

// 9ms 96.05% 43.4MB 62.49%
// brute force, hash map
// O(max(N,M)) O(max(N,M))
// N: word1 len
// M: word2 len
class Solution {
    public boolean isItPossible(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int[] freqs1 = new int[26];
        int[] freqs2 = new int[26];
        for (int i = 0; i < n; ++i) {
            freqs1[word1.charAt(i) - 'a']++;
        }
        for (int i = 0; i < m; ++i) {
            freqs2[word2.charAt(i) - 'a']++;
        }
        int uniqCnt1 = 0, uniqCnt2 = 0;
        for (int i = 0; i < 26; ++i) {
            if (freqs1[i] > 0) {
                uniqCnt1++;
            }
            if (freqs2[i] > 0) {
                uniqCnt2++;
            }
        }
        // Absolutely true
        if (uniqCnt1 == uniqCnt2 && n == m) {
            return true;
        }
        // Consider every cases
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (freqs1[i] == 0 || freqs2[j] == 0) {
                    continue;
                }
                int cnt1 = uniqCnt1, cnt2 = uniqCnt2;
                // Update word1 cnt
                if (freqs1[j] == 0) {
                    cnt1++;
                }
                freqs1[j]++;
                if (freqs1[i] == 1) {
                    cnt1--;
                }
                freqs1[i]--;
                // Update word2 cnt
                if (freqs2[i] == 0) {
                    cnt2++;
                }
                freqs2[i]++;
                if (freqs2[j] == 1) {
                    cnt2--;
                }
                freqs2[j]--;
                // Check distinct counts
                if (cnt1 == cnt2) {
                    return true;
                }
                // Reset freqs1, freqs2
                freqs1[j]--;
                freqs1[i]++;
                freqs2[i]--;
                freqs2[j]++;
            }
        }
        return false;
    }
}
