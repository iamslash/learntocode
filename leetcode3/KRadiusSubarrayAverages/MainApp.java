// Copyright (C) 2022 by iamslash

import java.util.*;

// 9ms 96.83% 62.2MB 89.97%
// sliding window
// O(N) O(N)
class Solution {
    public int[] getAverages(int[] nums, int k) {
        if (k <= 0) {
            return nums;           
        }
        long ps = 0;
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int wndLen = k * 2 + 1;
        for (int i = 0; i < n; ++i) {
            // Add new one
            ps += nums[i];
            // Sub old one
            if (i - wndLen >= 0) {
                ps -= nums[i - wndLen];
            }
            // Save avg
            if (i >= wndLen - 1) {
                ans[i-k] = (int)(ps / wndLen);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
