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

//          1
//       5     3
//     2   3  3  1

// 6ms 100.00% 54.8MB 50.00%
// dfs
// O(N) O(1)
class Solution {
    public int minIncrements(int n, int[] cost) {
        int ans = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int l = i * 2 + 1, r = i * 2 + 2;
            ans += Math.abs(cost[l] - cost[r]);
            cost[i] += Math.max(cost[l], cost[r]);
        }
        return ans;
    }
}
