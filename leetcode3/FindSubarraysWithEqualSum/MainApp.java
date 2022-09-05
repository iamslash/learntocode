// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 99.61% 42.3MB 38.83%
// sliding window, set
// O(N) O(N)
class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> sumSet = new HashSet<>();
        for (int i = 1; i < nums.length; ++i) {
            int sum = nums[i-1] + nums[i];
            if (sumSet.contains(sum)) {
                return true;
            }
            sumSet.add(sum);
        }
        return false;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
