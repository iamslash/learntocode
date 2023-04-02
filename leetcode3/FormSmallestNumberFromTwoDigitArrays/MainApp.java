// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 40.7MB 100.00%
// brute force
// O(1) O(1)
class Solution {
    private void dump(int[] nums) {
        for (int num : nums) {
            System.out.printf("%d ", num);
        }
        System.out.println("");
    }
    public int minNumber(int[] nums1, int[] nums2) {
        int[] freq1 = new int[10];
        int[] freq2 = new int[10];
        for (int num : nums1) {
            freq1[num]++;
        }
        for (int num : nums2) {
            freq2[num]++;
        }
        // dump(freq1);
        // dump(freq2);
        // Check same num
        for (int i = 1; i < 10; ++i) {
            if (freq1[i] > 0 && freq2[i] > 0) {
                return i;
            }
        }

        // Combine least num
        int digit1 = -1, digit2 = -1;
        for (int i = 1; i < 10; ++i) {
            if (digit1 < 0 && freq1[i] > 0) {
                digit1 = i;
            }
            if (digit2 < 0 && freq2[i] > 0) {
                digit2 = i;
            }
        }
        if (digit1 > digit2) {
            return digit2 * 10 + digit1;
        }
        return digit1 * 10 + digit2;
    }
}
