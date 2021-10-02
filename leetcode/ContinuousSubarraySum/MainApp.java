// Copyright (C) 2021 by iamslash

import java.util.*;

// 15ms 73.72% 55.4MB 66.50%
// partital su, hash map
// O(N) O(N)
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        // { mode : index }
        Map<Integer, Integer> modMap = new HashMap<>();
        modMap.put(0, -1);
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                nums[i] += nums[i-1];
            }
            int mod = nums[i] % k;
            if (modMap.containsKey(mod)) {
                if (i - modMap.get(mod) >= 2) {
                    return true;
                }
            } else {
                modMap.put(mod, i);
            }
        }
        return false;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
