// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 22 33 22 33 22
//       22 22 22 22 22
//          11    11
//
//       22
//
// nums: 10 12 13 14 15
//       11 11 11 11 11
//        1  1  2  3  4
//       11

// Idea: sort
//
// Sort nums.
// Find the middle num of nums.
// Find the left, right nearest palindrome from the middle num.
// Find both answers.
// Choose the minimum one.

// 48ms 33.37% 56.5MB 20.43%
// sort
// O(NlgN) O(1)
class Solution {
    private boolean isPalindrome(int num) {
        int reversed = 0;
        int tmp = num;
        while (tmp != 0) {
            reversed = (reversed * 10) + (tmp % 10);
            tmp = tmp / 10;
        }
        return reversed == num;
    }
    private int[] getNearestPalindrome(int num) {
        int rst[] = new int[]{-1, -1};
        int leftNum = num, rightNum = num + 1;
        boolean found = false;
        while (rst[0] == -1) {
            if (isPalindrome(leftNum)) {
                rst[0] = leftNum;
            }
            leftNum--;
        }
        while (rst[1] == -1) {
            if (isPalindrome(rightNum)) {
                rst[1] = rightNum;
            }
            rightNum++;
        }
        return rst;
    }
    public long minimumCost(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] pals = getNearestPalindrome(nums[n / 2]);
        long rst1 = 0L, rst2 = 0L;
        for (int num : nums) {
            if (pals[0] != -1) {
                rst1 += Math.abs(num - pals[0]);
            }
            if (pals[1] != -1) {
                rst2 += Math.abs(num - pals[1]);
            }
        }
        if (pals[0] != -1 && pals[1] != -1) {
            return Math.min(rst1, rst2);
        } else if (pals[0] != -1) {
            return rst1;
        }
        return rst2;
    }
}
