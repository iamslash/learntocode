// Copyright (C) 2022 by iamslash

import java.util.*;


// Idea: math
//
// ceil of avg sum is (sum + i) / (i + 1)

//                 i
// nums:  3  7  1  6
//  sum:  3 11 12 18
//  ans:  3  5  5  5

// 23ms 48.03% 83.2MB 28.15%
// math
// O(N) O(1)
class Solution {
    public int minimizeArrayValue(int[] nums) {
        long sum = 0, ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            ans = Math.max(ans, (sum + i) / (i + 1));
        }
        return (int)ans;
    }
}
 
public class MainApp {
  public static void main(String[] args) {
  }
}
