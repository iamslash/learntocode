// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 6
//       i
// nums: 3 6 2 7 1
//       j
//  ans: 

// 21ms 88.72% 42MB 85.59%
// math
// O(N^2) O(1)
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    private int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    public int subarrayLCM(int[] nums, int k) {
        int n = nums.length, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (k % nums[i] > 0) {
                continue;
            }
            int last = 1;
            for (int j = i; j < n; ++j) {
                last = lcm(last, nums[j]);
                if (last == k) {
                    ans++;
                } else if (last > k) {
                    break;
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
