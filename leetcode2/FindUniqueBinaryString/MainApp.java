// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 90.50% 39.1MB 42.30%
// Cantor's diagonal argument
// O(N) O(N)
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0, j = 0; i < nums.length; ++i, ++j) {
            sb.append(nums[i].charAt(i) == '0' ? '1' : '0');
        }
        return sb.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
