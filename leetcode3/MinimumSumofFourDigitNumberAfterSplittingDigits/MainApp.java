// Copyright (C) 2022 by iamslash

import java.util.*;

// num: 4009
//      

// 0ms 100.00% 38.7MB 33.33%
// sort
// O(1) O(1)
class Solution {
    public int minimumSum(int num) {
        int[] nums = new int[4];
        for (int i = 0; i < 4; ++i) {
            nums[i] = num % 10;
            num /= 10;
        }
        Arrays.sort(nums);
        return nums[0] * 10 + nums[2] + nums[1] * 10 + nums[3];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
