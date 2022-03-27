// Copyright (C) 2022 by iamslash

import java.util.*;

// nums1: 1 2 3 3
//        1 2 3
//        1 1 2
// nums2: 1 1 2 2
//        1 2
//        2 2

// 9ms 66.67% 54.8MB 66.67%
// hash map
// O(N) O(1)
class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] freqs1 = new int[2001], freqs2 = new int[2001];
        for (int i = 0; i < nums1.length; ++i) {
            freqs1[nums1[i] + 1000]++;
        }
        for (int i = 0; i < nums2.length; ++i) {
            freqs2[nums2[i] + 1000]++;
        }
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> nums1List = new ArrayList<>();
        List<Integer> nums2List = new ArrayList<>();
        ans.add(nums1List);
        ans.add(nums2List);
        for (int num = -1000; num <= 1000; ++num) {
            int idx = num + 1000;
            if (freqs1[idx] > 0 && freqs2[idx] == 0) {
                nums1List.add(num);
            } else if (freqs1[idx] == 0 && freqs2[idx] > 0) {
                nums2List.add(num);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
