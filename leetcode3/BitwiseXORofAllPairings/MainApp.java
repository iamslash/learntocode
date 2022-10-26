// Copyright (C) 2022 by iamslash

import java.util.*;

// nums1: a b
// nums2: c d e
//        a ^ c ^ a ^ d ^ a ^ e
//        b   c   b   d   b   e

// 6ms 31.92% 85.7MB 37.01%
// bit manipulation
// O(N) O(1)
class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length, ans = 0;
        if (n % 2 > 0) {
            for (int num : nums2) {
                ans ^= num;
            }
        }
        if (m % 2 > 0) {
            for (int num : nums1) {
                ans ^= num;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
