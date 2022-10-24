// Copyright (C) 2022 by iamslash

import java.util.*;

// 16ms 70.00% 96.1MB 60.00%
// DFS
// O(N) O(N)
class Solution {
    private int dfs(int[] nums, int u) {
        int cnt = nums[u];
        // recursion
        if (u*2 < nums.length) {
            nums[u*2] ^= nums[u];
            cnt += dfs(nums, u*2);
        }
        if (u*2 + 1 < nums.length) {
            nums[u*2 + 1] ^= nums[u];
            cnt += dfs(nums, u*2 + 1);
        }
        return cnt;
    }
    public int numberOfNodes(int n, int[] queries) {
        int[] nums = new int[n+1];
        for (int query : queries) {
            nums[query] ^= 1;
        }
        return dfs(nums, 1);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
