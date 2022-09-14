// Copyright (C) 2022 by iamslash

import java.util.*;

// 1 1 2
// 2 3 3
// 1 3 4

// 67ms 28.95% 93MB 57.89%
// sort
// O(HWlgHW) O(HW)
class Solution {
    public int matrixMedian(int[][] grid) {
        int h = grid.length, w = grid[0].length, n = h * w;
        int[] nums = new int[n];
        int i= 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                nums[i++] = grid[y][x];
            }
        }
        Arrays.sort(nums);
        return nums[(n-1)/2];
    }
}

// 14ms 36.84% 93.6MB 46.49%
// binary search
// O(HW) O(1) 
class Solution {
    // binary search left most equal
    private int binarySearch(int[] nums, int tgt) {
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (nums[mi] < tgt) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return nums[lo] >= tgt ? lo : nums.length;
    }
    // binary search right most equal
    public int matrixMedian(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int lo = 1, hi = 1_000_000, k = h * w / 2 + 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            int cnt = 0;
            for (int[] row: grid) {
                cnt += w - binarySearch(row, mi);
            }
            if (cnt >= k) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return lo;
    }
}
