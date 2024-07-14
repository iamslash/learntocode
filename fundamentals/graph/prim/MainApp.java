// Copyright (C) 2024 by iamslash

import java.util.*;

// prim
// O(N^2) O(N)
class Solution {
    private int getDist(int[][] pts, int u, int v) {
        return Math.abs(pts[u][0] - pts[v][0]) +
                Math.abs(pts[u][1] - pts[v][1]);
    }

    public int prim(int[][] points) {
        int n = points.length, ans = 0;
        Set<Integer> mst = new HashSet<>();
        mst.add(0);
        int[] dists = new int[n];

        for (int i = 1; i < n; ++i) {
            dists[i] = getDist(points, 0, i);
        }

        while (mst.size() < n) {
            int next = -1;
            for (int i = 0; i < n; ++i) {
                if (mst.contains(i)) {
                    continue;
                }
                if (next == -1 || dists[next] > dists[i]) {
                    next = i;
                }
            }

            mst.add(next);
            ans += dists[next];

            for (int i = 0; i < n; ++i) {
                if (!mst.contains(i)) {
                    dists[i] = Math.min(dists[i], getDist(points, i, next));
                }
            }
        }

        return ans;

    }
}
