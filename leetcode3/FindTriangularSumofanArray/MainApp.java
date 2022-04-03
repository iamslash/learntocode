// Copyright (C) 2022 by iamslash

import java.util.*;

// 97ms 33.33% 48.9MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        for (int j = n-1; j > 0; --j) {
            for (int i = 0; i < j; ++i) {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
        }
        return nums[0];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
