// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 2 3 4 6 8 16

// nums: 2 3 5 6 7

// 79ms 72.72% 61.1MB 88.55%
// sort, hash map
// O(NlgN) O(N)
class Solution {
    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        Map<Integer, Integer> freqMap = new HashMap<>();
        int maxFreq = 0, n = nums.length;
        for (int i = n - 1; i >= 0; --i) {
            freqMap.put(nums[i],
                        freqMap.getOrDefault(nums[i] * nums[i], 0) + 1);
            maxFreq = Math.max(maxFreq, freqMap.get(nums[i]));
        }
        if (maxFreq > 1) {
            return maxFreq;
        }
        return -1;
    }
}
