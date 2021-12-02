// Copyright (C) 2021 by iamslash

import java.util.*;

// nums: 1 10 7 5 4 1 8 6
//       --->       <----
//       ----------->
//         <-------------

// 2ms 9.94% 57.8MB 71.29%
// math
// O(N) O(1)
class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        if (n <= 2) {
            return n;
        }
        int minVal = nums[0], minPos = 0;
        int maxVal = nums[0], maxPos = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < minVal) {
                minPos = i;
                minVal = nums[i];
            }
            if (nums[i] > maxVal) {
                maxPos = i;
                maxVal = nums[i];
            }
        }
        int leftPos = Math.min(minPos, maxPos);
        int rightPos = Math.max(minPos, maxPos);
        int leftVal = nums[leftPos], rightVal = nums[rightPos];
        int bothCnt = leftPos + 1 + n - rightPos;
        int leftCnt = rightPos + 1;
        int rightCnt = n - leftPos;
        return Math.min(bothCnt, Math.min(leftCnt, rightCnt));
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
