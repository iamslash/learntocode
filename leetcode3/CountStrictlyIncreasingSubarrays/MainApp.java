// Copyright (C) 2022 by iamslash

import java.util.*;

//                     i
// nums:   1 3 5 4 4 6
// prev: 0 1 2 3 1 1 2     

// 3ms 87.6% 85MB 81.33%
// brute force
// O(N) O(1)
class Solution {
    public long countSubarrays(int[] nums) {
        long ans = 0, con = 1;
        int n = nums.length;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] >= nums[i]) {
                ans += con * (con + 1) / 2;
                con = 1;
            } else {
                con++;
            }
        }
        ans += con * (con + 1) / 2;
        return ans;
    }
}

// 12ms 22.78% 93.5MB 18.6%
// brute force
// O(N) O(1)
class Solution {
    public long countSubarrays(int[] nums) {
        long prv = 1, ans = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i-1] < nums[i]) {
                prv++;
            } else {
                prv = 1;
            }
            ans += prv;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
