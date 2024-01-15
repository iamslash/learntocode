// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42MB 33.33%
// brute force
// O(N) O(1)
class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] cnts = new int[101];
        int maxFreq = 0, maxNumCnt = 0;
        for (int num : nums) {
            maxFreq = Math.max(maxFreq, ++cnts[num]);
        }
        for (int cnt : cnts) {
            if (cnt == maxFreq) {
                // System.out.printf("cnt: %d, maxFreq: %d\n", cnt, maxFreq);
                maxNumCnt++;
            }
        }
        // System.out.printf("maxNumCnt: %d, maxFreq: %d\n", maxNumCnt, maxFreq);
        return maxNumCnt * maxFreq;
    }
}
