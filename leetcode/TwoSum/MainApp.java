// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 67.04% 42.6MB 12.53%
// hash set
// O(N) O(N)
class Solution {
    public int[] twoSum(int[] nums, int tgt) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            int opp = tgt - num;
            if (numMap.containsKey(opp)) {
                return new int[]{i, numMap.get(opp)};
            }
            numMap.put(num, i);
        }
        return null;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
