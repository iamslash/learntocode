// Copyright (C) 2025 by iamslash

import java.util.*;

// Idea: dfs, bit manipulation
//
// 1 <= n <= 10

// 20ms 42.86% 52.76MB 5.71%
// backtracking, bit manipulation
// O(2^N * N) O(N)
class Solution {
    private void dfs(int n, List<List<Integer>> cands,
                     List<Integer> path, int state, int last) {
        if (path.size() == n) {
            cands.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < n; i++) {
            if ((state & (1 << i)) != 0 ||
                (last != -1 && (i + 1) % 2 == last % 2)) {
                continue;
            }

            path.add(i + 1);
            dfs(n, cands, path, state | (1 << i), i + 1);
            path.remove(path.size() - 1);
        }
    }

    public int[][] permute(int n) {
        List<List<Integer>> cands = new ArrayList<>();
        dfs(n, cands, new ArrayList<>(), 0, -1);

        int[][] ans = new int[cands.size()][n];
        for (int i = 0; i < cands.size(); i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = cands.get(i).get(j);
            }
        }
        return ans;
    }
}
