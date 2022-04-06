// Copyright (C) 2022 by iamslash

import java.util.*;

// 25ms 100.00% 115MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    public boolean isConsecutive(int[] nums) {
        int[] slots = new int[100_001];
        int minNum = nums[0], maxNum = nums[0];
        for (int num : nums) {
            if (slots[num]++ > 0) {
                return false;
            }
            minNum = Math.min(minNum, num);
            maxNum = Math.max(maxNum, num);
        }
        if (maxNum - minNum + 1 != nums.length) {
            return false;
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
