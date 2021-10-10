// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 91.67% 43.5MB 8.33%
// hash map
// O(N) O(N)
class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        int[] freqs1 = new int[101];
        int[] freqs2 = new int[101];
        int[] freqs3 = new int[101];
        List<Integer> ans = new ArrayList<>();
        for (int num : nums1) {
            if (freqs1[num] == 0) {
                freqs1[num]++;
            }
        }
        for (int num : nums2) {
            if (freqs2[num] == 0) {
                freqs2[num]++;
            }
        }
        for (int num : nums3) {
            if (freqs3[num] == 0) {
                freqs3[num]++;
            }
        }
        for (int num = 1; num <= 100; ++num) {
            if (freqs1[num] + freqs2[num] + freqs3[num] >= 2) {
                ans.add(num);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
