// Copyright (C) 2023 by iamslash

// 11ms 50.00% 551.1MB 25.00%
// dfs
// O(N) O(lgN)
class Solution {
    private int diffSum = 0;
    private int dfs(int i, int[] cost) {
        // System.out.println(i);
        int n = cost.length;
        // base
        if (i >= n) {
            return 0;
        }
        // recursion
        int lsum = dfs(i * 2 + 1, cost);
        int rsum = dfs(i * 2 + 2, cost);
        int diff = Math.abs(lsum - rsum);
        diffSum += diff;
        return cost[i] + Math.max(lsum, rsum);
    }
    public int minIncrements(int n, int[] cost) {
        dfs(0, cost);
        return diffSum;
    }
}
