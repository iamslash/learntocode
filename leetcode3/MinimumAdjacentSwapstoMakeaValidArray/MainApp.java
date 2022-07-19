// Copyright (C) 2022 by iamslash

import java.util.*;

//             M
// nums: 3 4 5 5 3 1
//                 m
//       1 3 4 5 5 3
//             5 3 5

// Idea:
//
// maxIdx: index of right most max numm
// minIdx: index of left most min num
//    ans: (n - 1 - maxIdx) + minIdx - (minIdx > maxIdx ? 1 : 0)

// 3ms 100.00% 80.3MB 100.00%
// math
// O(N) O(1)
class Solution {
    public int minimumSwaps(int[] nums) {
        int n = nums.length, maxIdx = n - 1, minIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }
            if (nums[n-1-i] > nums[maxIdx]) {
                maxIdx = n-1-i;
            }
        }
        return (n - 1 - maxIdx) + minIdx - (minIdx > maxIdx ? 1 : 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
