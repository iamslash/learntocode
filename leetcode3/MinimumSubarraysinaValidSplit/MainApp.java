// Copyright (C) 2022 by iamslash

import java.util.*;
//                 i
// nums: 2 6 3 4 3
//       j
//    C: 0 M M M M M


// 421ms 100.00% 42.7MB 100.00%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    private int gcd(int a, int b) {
        // base
        if (b == 0) {
            return a;
        }
        // recursion
        return gcd(b, a % b);
    }
    public int validSubarraySplit(int[] nums) {
        int n = nums.length;
        // C[i]: min split count of subarray ends with nums[i-1]
        int[] C = new int[n+1];
        Arrays.fill(C, Integer.MAX_VALUE);
        C[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (gcd(nums[j], nums[i-1]) != 1 &&
                    C[j] != Integer.MAX_VALUE) {
                    C[i] = Math.min(C[i], C[j] + 1);
                }
            }
        }
        if (C[n] == Integer.MAX_VALUE) {
            return -1;
        }
        return C[n];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
