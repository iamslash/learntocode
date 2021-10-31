// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 39.2MB 66.67%
// math
// O(1) O(1)
class Solution {
    public int smallestEqual(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
