// Copyright (C) 2022 by iamslash

import java.util.*;

//           i
// nums: 0 0 2 2 4 10

// 2ms 83.33% 41.4MB 66.67%
// sort, hash map
// O(N) O(1)
class Solution {
    public int distinctAverages(int[] nums) {
        int n = nums.length;
        int[] freqs = new int[201];
        Arrays.sort(nums);
        Arrays.fill(freqs, -1);
        for (int i = 0; i < n / 2; ++i) {
            freqs[nums[i] + nums[n - i - 1]]++;
            // System.out.printf("%d %d\n",a nums[i], nums[n-i-1]);
        }
        int ans = 0;
        for (int i = 0; i < freqs.length; ++i) {
            if (freqs[i] >= 0) {
                ans++;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
