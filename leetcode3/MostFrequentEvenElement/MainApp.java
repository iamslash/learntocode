// Copyright (C) 2022 by iamslash

import java.util.*;

// 21ms 93.14% 42.6MB 86.98%
// hash map
// O(N) O(N)
class Solution {
    public int mostFrequentEven(int[] nums) {
        final int MAXNUM = 100_001;
        int[] freqs = new int[MAXNUM];
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] % 2 > 0) {
                continue;
            }
            freqs[nums[i]]++;
        }
        int minNum = -1, maxFreq = 0;
        for (int a = 0; a < MAXNUM; ++a) {
            if (freqs[a] > maxFreq) {
                minNum = a;
                maxFreq = freqs[a];
            }
        }
        return minNum;
    }
}
