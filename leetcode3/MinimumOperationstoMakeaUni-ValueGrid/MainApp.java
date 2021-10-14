// Copyright (C) 2021 by iamslash

import java.util.*;

// odd + odd = odd
// odd + evn = odd
// evn + odd = odd
// evn + evn = evn

// 2 4    4 6
// 6 8   
// nums: 2 4 6 8

//    x: 10
// nums: 2 4 6 8
//  ans: 

//    x: 10
// nums: 2 4 6 8

// 32ms 92.96% 69.2MB 71.22%
// sort
// O(NlgN) O(N)
// N: H * W
class Solution {
    public int minOperations(int[][] grid, int x) {
        int h = grid.length, w = grid[0].length, n = h * w;
        int[] nums = new int[n];
        int k = 0, ans = 0;
        // Build nums
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                nums[k++] = grid[i][j];
            }
        }
        // Find median
        Arrays.sort(nums);
        int median = nums[(n-1)/2];
        // Update ans
        for (int num : nums) {
            if (num == median) {
                continue;
            }
            int diff = Math.abs(num - median);
            if (diff % x != 0) {
                return -1;
            }
            ans += (diff / x);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
