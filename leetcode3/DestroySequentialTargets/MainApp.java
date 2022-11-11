// Copyright (C) 2022 by iamslash

import java.util.*;

// space: 2
//        i
//  nums: 3 7 8 1 1 5
//  fmap: 0 1  
//        1 5

// 83ms 60.31% 74MB 71.74%
// hash map
// O(N) O(N)
class Solution {
    public int destroyTargets(int[] nums, int space) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            int key = num % space;
            freqMap.put(key, freqMap.getOrDefault(key, 0) + 1);
        }
        int maxCnt = 0;
        for (int rem : freqMap.keySet()) {
            int cnt = freqMap.get(rem);
            maxCnt = Math.max(maxCnt, cnt);
        }
        int minNum = Integer.MAX_VALUE;
        for (int num : nums) {
            if (freqMap.get(num % space) == maxCnt && num < minNum) {
                minNum = num;
            }
        }
        return minNum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
