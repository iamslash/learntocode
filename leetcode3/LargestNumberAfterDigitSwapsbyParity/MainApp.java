// Copyright (C) 2022 by iamslash

import java.util.*;

// Caveats:
// odd digit does not mean odd position
// even digit does not mean even position

// 1ms 100.00% 41.1MB 66.67%
// sort
// O(N^2) O(N)
class Solution {
    public int largestInteger(int num) {
        char[] nums = Integer.toString(num).toCharArray();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[i] % 2 == nums[j] % 2 && nums[i] < nums[j]) {
                    char tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return Integer.parseInt(new String(nums));
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
