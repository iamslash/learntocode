// Copyright (C) 2022 by iamslash

import java.util.*;

//       i 
// nums: 3 -1 1 2
//

// Idea:
// 0. Add num
// 1. Sub num
// 2. Start new subarray with adding num

// 5ms 79.31% 75.8MB 34.48%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long maximumAlternatingSubarraySum(int[] nums) {
        long lastAdd = Integer.MIN_VALUE;
        long lastSub = Integer.MIN_VALUE;
        long ans = Integer.MIN_VALUE;
        for (int num : nums) {
            long curAdd = Math.max(lastSub + num, num);
            lastSub = lastAdd - num;
            lastAdd = curAdd;
            ans = Math.max(ans, Math.max(lastAdd, lastSub));
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
