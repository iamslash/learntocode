// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 50.00% 42.6MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int findClosestNumber(int[] nums) {
        int closestNum = nums[0], closestAbs = Math.abs(nums[0]);
        for (int num : nums) {
            if ((Math.abs(num) < closestAbs) ||
                (Math.abs(num) == closestAbs && closestNum < num)) {
                closestNum = num;
                closestAbs = Math.abs(num);
            }
        }
        return closestNum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
