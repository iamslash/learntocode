// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 10 20 30
//        i
// bnds: 10 20 30

// 84ms 49.15% 43.5MB 44.07%
// recursive dynamic programming
// O(N^2) O(N^2)
class Solution {
    private final int MAX_VAL = 200_000_000;
    private int dfs(int[][] C, int i, int[] nums, int k) {
        int n = nums.length;
        // base
        if (i == n) {
            return 0;
        }
        if (k < 0) {
            return MAX_VAL;
        }
        // memo
        if (C[i][k] >= 0) {
            return C[i][k];
        }
        // recursion
        int ans = MAX_VAL, maxNum = nums[i], sum = 0;
        for (int j = i; j < n; ++j) {
            maxNum = Math.max(maxNum, nums[j]);
            sum += nums[j];
            int wasteSum = (j - i + 1) * maxNum - sum;
            ans = Math.min(ans, wasteSum + dfs(C, j+1, nums, k-1));
        }
        return C[i][k] = ans;
    }
    public int minSpaceWastedKResizing(int[] nums, int k) {
        int[][] C = new int[nums.length+1][k+1];
        for (int[] line : C) {
            Arrays.fill(line, -1);
        }
        return dfs(C, 0, nums, k);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
