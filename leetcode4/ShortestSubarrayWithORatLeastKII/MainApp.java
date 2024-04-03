// Copyright (C) 2024 by iamslash

// 2 1 8
//    i
// 0010 0001 1000 

// 61ms 49.32% 70MB 91.23%
// sliding window
// O(N) O(1)
class Solution {
    private void updateWnd(int[] bits, int num, int delta) {
        for (int i = 0; i < bits.length; ++i) {
            if (((num >> i) & 1) != 0) {
                bits[i] += delta;
            }
        }
    }

    private int bitsToNum(int[] bits) {
        int rst = 0;

        for (int i = 0; i < 32; ++i) {
            if (bits[i] != 0) {
                rst |= 1 << i;
            }
        }

        return rst;
    }
    
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length, minWndLen = n + 1;
        int[] bits = new int[32];

        for (int i = 0, j = 0; j < n; ++j) {
            updateWnd(bits, nums[j], 1);
            while (i <= j && bitsToNum(bits) >= k) {
                minWndLen = Math.min(minWndLen, j - i + 1);
                updateWnd(bits, nums[i++], -1);
            }
        }

        if (minWndLen == n + 1) {
            return -1;
        }
        return minWndLen;
    }
}
