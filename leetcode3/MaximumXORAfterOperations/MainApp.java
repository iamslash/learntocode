// Copyright (C) 2022 by iamslash

import java.util.*;

//
// nums: 3 2 4 6
//
//         1 1
//         1 0
//       1 0 0
//       1 1 0

// nums: 1 2 3 9 2
//
//       0 0 0 1
//       0 0 1 0
//       0 0 1 1  
//       1 0 0 1
//       0 0 1 0

// 2ms 77% 73.5MB 71.65%
// bit manipulation
// O(N) O(1)
class Solution {
    public int maximumXOR(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            ans |= num;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
