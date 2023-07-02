// Copyright (C) 2023 by iamslash

import java.util.*;

//         i
// cost: 1 2 3 2
// time: 1 2 3 2

// dfs(0, 4)
//   dfs(1, 4)
//     dfs(2, 4)
//       dfs(3, 4)
//         dfs(4, 4)
//         - dfs(4, 4): M
//         dfs(4, 1)
//         - dfs(4, 1): M
//       - dfs(3, 4): 1000000000
//       dfs(3, 0)
//       - dfs(3, 0): 0
//     - dfs(2, 4): 3
//     dfs(2, 1)
//       dfs(3, 1)
//         dfs(4, 1)
//         - dfs(4, 1): M
//         dfs(4, -2)
//         - dfs(4, -2): 0
//       - dfs(3, 1): 2
//       dfs(3, -3)
//       - dfs(3, -3): 0
//     - dfs(2, 1): 2
//   - dfs(1, 4): 3
//   dfs(1, 2)
//     dfs(2, 2)
//       dfs(3, 2)
//         dfs(4, 2)
//         - dfs(4, 2): M
//         dfs(4, -1)
//         - dfs(4, -1): 0
//       - dfs(3, 2): 2
//       dfs(3, -2)
//       - dfs(3, -2): 0
//     - dfs(2, 2): 2
//     dfs(2, -1)
//     - dfs(2, -1): 0
//   - dfs(1, 2): 2
// - dfs(0, 4): 3

// 59ms 63.31% 43.9MB 82.25%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    private void dumpTabs(int indent) {
        for (int i = 0; i < indent; ++i) {
            System.out.printf("  ");
        }
    }
    private int dfs(int[] costs, int[] times, int[][] C, int pos, int walls) {
        dumpTabs(pos);
        System.out.printf("dfs(%d, %d)\n", pos, walls);
        int n = costs.length;
        // base
        if (walls <= 0) {
            dumpTabs(pos);
            System.out.printf("- dfs(%d, %d): 0\n", pos, walls);
            return 0;
        }
        if (pos == n) {
            dumpTabs(pos);
            System.out.printf("- dfs(%d, %d): M\n", pos, walls);
            return 1_000_000_000;
        }
        // memo
        if (C[pos][walls] >= 0) {
            return C[pos][walls];
        }
        // recursion
        int notTaken = dfs(costs, times, C, pos + 1, walls);
        int taken = costs[pos] + dfs(costs, times, C, pos + 1, walls - times[pos] - 1);
        int minCost = Math.min(notTaken, taken);
        dumpTabs(pos);
        System.out.printf("- dfs(%d, %d): %d\n", pos, walls, minCost);
        
        return C[pos][walls] = minCost;
    }
    public int paintWalls(int[] cost, int[] time) {
        int n = cost.length;
        int[][] C = new int[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            Arrays.fill(C[i], -1);
        }
        return dfs(cost, time, C, 0, n);
    }
}

// 13ms 94.96% 44.4MB 61.27%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int paintWalls(int[] cost, int[] time) {
        int n = cost.length, C[] = new int[n + 1];
        Arrays.fill(C, 1_000_000_000);
        C[0] = 0;
        // i: wall index to be painted by painter-1
        // w: remained count of walls to be painted
        for (int i = 0; i < n; ++i) {
            for (int w = n; w > 0; --w) {
                C[w] = Math.min(C[w],
                                cost[i] + C[Math.max(w - time[i] - 1, 0)]);
            }
        }
        return C[n];
    }
}
