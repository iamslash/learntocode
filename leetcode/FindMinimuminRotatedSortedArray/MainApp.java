// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 42MB 28.43%
// brute force
// O(N) O(1)
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length, i = 0;

        if (n == 1) {
            return nums[0];
        }

        // Probe min number
        for (i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                break;
            }
        }

        if (i == n) {
            return nums[0];
        }
        return nums[i];
    }
}

//             l
// nums: 3 4 5 1 2
//             h
//             m

// 0ms 100.00% 42.4MB 7.54%
// binary search
// O(lgN) O(1)
class Solution {
    public int findMin(int[] nums) {
        int lo = 0, hi = nums.length - 1;

        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;

            if (nums[mi] > nums[hi]) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }

        return nums[lo];
    }
}
