// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 3 1 3 2 4 3
//       3   3   3
//         1   1   1
//
// nums: 3 3 3 3 4
//       3   3   3
//         2   2
//       

// 150ms 41.86% 127.3MB 28.49%
// hash map, top 2 freqs
// O(N) O(N)
class Solution {
    private int[] max2freq(int[] nums, int beg) {
        int firstNum = 0, secondNum = 0, n = nums.length;
        int cnts[] = new int[100001];
        for (int i = beg; i < n; i += 2) {
            ++cnts[nums[i]];
            if (cnts[nums[i]] >= cnts[firstNum]) {
                if (nums[i] != firstNum) {
                    secondNum = firstNum;
                }
                firstNum = nums[i];
            } else if (cnts[nums[i]] > cnts[secondNum]) {
                secondNum = nums[i];
            }
        }
        return new int[]{firstNum, cnts[firstNum], cnts[secondNum]};
    }
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> evnFreqMap = new HashMap<>();
        Map<Integer, Integer> oddFreqMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                evnFreqMap.put(nums[i], evnFreqMap.getOrDefault(nums[i], 0) + 1);
            } else {
                oddFreqMap.put(nums[i], oddFreqMap.getOrDefault(nums[i], 0) + 1);
            }
        }
        // [1st max number, count of 1st max number, count of 2nd max number]
        int[] evnMaxFreqs = max2freq(nums, 0);
        int[] oddMaxFreqs = max2freq(nums, 1);
        if (evnMaxFreqs[0] == oddMaxFreqs[0]) {
            return n - Math.max(evnMaxFreqs[1] + oddMaxFreqs[2],
                                evnMaxFreqs[2] + oddMaxFreqs[1]);
        }
        return n - evnMaxFreqs[1] - oddMaxFreqs[1];
    }
}
