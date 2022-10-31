// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 84.08% 98.8MB 22.95%
// brute force
// O(N) O(1)
class Solution {
    public int longestSubarray(int[] nums) {
        int maxNum = 0, n = nums.length, glbMax = 0, locMax = 0;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
        }
        for (int num : nums) {
            if (num == maxNum) {
                glbMax = Math.max(glbMax, ++locMax);
            } else {
                locMax = 0;
            }
        }
        return glbMax;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
