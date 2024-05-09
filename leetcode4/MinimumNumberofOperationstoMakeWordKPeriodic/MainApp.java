// Copyright (C) 2024 by iamslash

import java.util.*;

// 32ms 88.29% 45.3MB 87.14%
// hash map
// O(N) O(N)
class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        int n = word.length(), maxFreq = 0;
        Map<String, Integer> freqMap = new HashMap<>();

        for (int i = 0; i < n; i += k) {
            String s = word.substring(i, Math.min(i + k, n));
            freqMap.put(s, freqMap.getOrDefault(s, 0) + 1);
        }

        for (int freq : freqMap.values()) {
            maxFreq = Math.max(maxFreq, freq);
        }

        return n / k - maxFreq;
    }
}
