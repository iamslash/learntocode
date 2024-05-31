// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.95% 42.9MB 29.35%
// brute force
// O(NM) O(1)
class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {
        int n = nums1.length, m = nums2.length;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (nums1[i] % (nums2[j] * k) == 0) {
                    cnt++;
                }
            }
        }

        return cnt;        
    }
}
