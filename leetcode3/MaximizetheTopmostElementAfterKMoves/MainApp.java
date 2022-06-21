// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 83.7MB 41.55%
// brute fore
// O(N) O(1)
class Solution {
    public int maximumTop(int[] nums, int k) {
        int n = nums.length;
        if (k == 0) {
            return n >= 1 ? nums[0] : -1;
        }
        if (k == 1) {
            return n == 1 ? -1 : nums[1];
        }
        if (n == 1) {
            return k % 2 == 0 ? nums[0] : -1;
        }
        int maxNum = 0, bnd = Math.min(k-1, n);
        for (int i = 0; i < bnd; ++i) { 
            maxNum = Math.max(maxNum, nums[i]);
        }
        if (k < n) {
            maxNum = Math.max(maxNum, nums[k]);
        }
        return maxNum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
