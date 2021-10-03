// Copyright (C) 2021 by iamslash

// 5ms 100.00% 49MB 60.00%
// brute force
// O(N) O(N)
class Solution {
    public int[][] construct2DArray(int[] nums, int m, int n) {
        int[][] ans = new int[m][n];
        if (m*n != nums.length) {
            return new int[0][];
        }
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                ans[y][x] = nums[n*y + x];
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
