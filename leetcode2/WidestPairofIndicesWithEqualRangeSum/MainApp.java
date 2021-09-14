// Copyright (C) 2021 by iamslash

import java.util.*;

//
//  nums1[i] + nums1[i+1] + ... + nums1[j] -
// (nums2[i] + nums2[i+1] + ... + nums2[j]) = 0
//
//  (  nums1[i] -   nums2[i]) +
//  (nums1[i+1] - nums2[i+1]) +
//  (          ...          ) +
//  (  nums1[j] -   nums2[j]) = 0
//
//               i    
//      nums1: 0 0 0
//      nums2: 0 1 1
// sum2idxMap: 0 1
//            -1 0
//        sum: 0
//        ans: 0

// 32ms 71.07% 60.4MB 76.03%
// hash map, partial sum
// O(N) O(N)
class Solution {
    public int widestPairOfIndices(int[] nums1, int[] nums2) {
        Map<Integer, Integer> sum2idxMap = new HashMap<>();
        sum2idxMap.put(0, -1);
        int maxWidth = 0, sum = 0, n = nums1.length;
        for (int i = 0; i < n; ++i) {
            sum += nums1[i] - nums2[i];
            maxWidth = Math.max(maxWidth, i - sum2idxMap.getOrDefault(sum, i));
            sum2idxMap.putIfAbsent(sum, i);
        }
        return maxWidth;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
