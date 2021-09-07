// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 38.1MB 96.05%
// partial sum
// O(N) O(N)
class Solution {
    public int findMiddleIndex(int[] nums) {
        int n = nums.length;
        int[] ps = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + nums[i];
        }
        int sum = ps[n];
        for (int i = 0; i < n; ++i) {
            if (ps[i] == ps[n] - ps[i+1]) {
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
