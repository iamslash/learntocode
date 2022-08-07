// Copyright (C) 2022 by iamslash

import java.util.*;

// nums[j] - nums[i] == diff
// nums[k] - nums[j] == diff
//
// nums[j] = nums[i] + diff
// nums[k] = nums[j] + diff

// 1ms 75.00% 42MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int n = nums.length;
        boolean[] freqs = new boolean[201];
        for (int i = 0; i < n; ++i) {
            freqs[nums[i]] = true;
        }
        int cnt = 0;
        for (int i = 0; i < n-2; ++i) {
            int numj = nums[i] + diff;
            if (numj > 200 || !freqs[numj]) {
                continue;
            }
            int numk = numj + diff;
            if (numk > 200 || !freqs[numk]) {
                continue;
            }
            cnt++;
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
