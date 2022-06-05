// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 44MB 25.00%
// brute force
// O(lgN) O(1)
class Solution {
    private void dump(int[] A, int n) {
        for (int i = 0; i < n; ++i) {
            System.out.printf("%d", A[i]);
        }
        System.out.println("----");
    }
    public int minMaxGame(int[] nums) {
        int n = nums.length;
        while (n > 1) {
            // dump(nums, n);
            for (int i = 0; i < n/2; ++i) {
                if (i % 2 == 0) {
                    nums[i] = Math.min(nums[2*i], nums[2*i+1]);
                } else {
                    nums[i] = Math.max(nums[2*i], nums[2*i+1]);
                }
            }
            n /= 2;
        }
        return nums[0];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
