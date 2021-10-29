// Copyright (C) 2021 by iamslash

import java.util.*;

//         k: 3
//      nums: 1 -1 5 -2 3
//       sum: 1  0 5  3 6
//                    i
// sumIdxMap: 0 1 5
//            0 1 3
//    maxLen: 3
//

// 33ms 64.76% 69.8MB 38.06%
// partial sum, hash map
// O(N) O(N)
class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int n = nums.length, maxLen = 0, sum = 0;
        Map<Integer, Integer> sumIdxMap = new HashMap<>();
        sumIdxMap.put(0, 0);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sumIdxMap.containsKey(sum - k)) {
                maxLen = Math.max(maxLen, i - sumIdxMap.get(sum - k) + 1);
            }
            sumIdxMap.putIfAbsent(sum, i+1);
        }
        return maxLen;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
