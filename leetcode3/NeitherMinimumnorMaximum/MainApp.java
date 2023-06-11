// Copyright (C) 2023 by iamslash

// 8ms 100.00% 43.8MB 40.00%
// brute force
// O(N) O(1)
class Solution {
    public int findNonMinOrMax(int[] nums) {
        if (nums.length <= 2) {
            return -1;
        }
        int minNum = 101, maxNum = 0, midNum = -1;
        for (int num : nums) {
            minNum = Math.min(minNum, num);
            maxNum = Math.max(maxNum, num);
        }
        for (int num : nums) {
            if (num > minNum && num < maxNum) {
                midNum = num;
                break;
            }
        }
        return midNum;
    }
}
