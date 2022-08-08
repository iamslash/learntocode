// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: math
// 
// total = good + bad
//   bad = total - good
// total = nCr
//
//       j - i != nums[j] - nums[i]
// i - nums[i] != j - nums[j]   : bad pair
// i - nums[i] == j - nums[j]   : good pair

// 94ms 40.00% 107.1MB 20.00%
// math
// O(N) O(N)
class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        long goodCnt = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            int key = i - nums[i];
            if (freqMap.containsKey(key)) {
                goodCnt += freqMap.get(key);
            }
            freqMap.put(key, freqMap.getOrDefault(key, 0) + 1);
        }
        return n * (n - 1) / 2 - goodCnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
