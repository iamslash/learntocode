// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
// Exhaustive search with DFS
// similar with Number of islands

// 109ms 79.86% 41.8MB 97.37%
// DFS
// O(N^2) O(N)
class Solution {
    private int cnt = 0;
    private boolean inside(int[] a, int[] b) {
        long dx = a[0] - b[0], dy = a[1] - b[1], r = a[2];
        return dx * dx + dy * dy <= r * r;
    }
    private void dfs(boolean[] visit, int[][] bombs, int u) {
        cnt++;
        visit[u] = true;
        for (int v = 0; v < bombs.length; ++v) {
            if (visit[v] == false && inside(bombs[u], bombs[v])) {
                dfs(visit, bombs, v);
            }
        }
    }
    public int maximumDetonation(int[][] bombs) {
        int maxCnt = 0, n = bombs.length;
        for (int i = 0; i < n; ++i) {
            cnt = 0;
            dfs(new boolean[n], bombs, i);
            maxCnt = Math.max(maxCnt, cnt);
        }
        return maxCnt;
    }
}
