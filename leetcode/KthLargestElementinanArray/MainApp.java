// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 79.16% 44.3MB 54.18%
// sort
// O(NlgN) O(1)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        return nums[n-k];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
