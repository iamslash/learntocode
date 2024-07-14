// Copyright (C) 2024 by iamslash

import java.util.*;

// 79ms 79.73% 45.2MB 90.44%
// prim
// O(N^2) O(N)
class Solution {
    private int getDist(int[][] pts, int u, int v) {
        return Math.abs(pts[u][0] - pts[v][0]) +
            Math.abs(pts[u][1] - pts[v][1]);
    }
    
    public int minCostConnectPoints(int[][] points) {
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


// 74ms 86.03% 66.9MB 36.47%
// kruskal
// O(ElgE) O(E)
class Solution {
    private int getDist(int[][] pts, int u, int v) {
        return Math.abs(pts[u][0] - pts[v][0]) +
            Math.abs(pts[u][1] - pts[v][1]);
    }

    class DisjointSet {
        int[] prnt;

        DisjointSet(int n) {
            this.prnt = new int[n];
            for (int i = 0; i < n; ++i) {
                prnt[i] = i;
            }
        }

        public void merge(int a, int b) {
            prnt[find(a)] = prnt[find(b)];
        }

        public int find(int u) {
            if (prnt[u] != u) {
                prnt[u] = find(prnt[u]);
            }
            return prnt[u];
        }
        
    }

    public int minCostConnectPoints(int[][] points) {
        int n = points.length, ans = 0;
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int c = getDist(points, u, v);
                pq.add(new int[]{c, u, v});
            }
        }

        int cnt = 0;
        DisjointSet ds = new DisjointSet(n);

        while (cnt < n - 1) {
            int[] top = pq.poll();
            int c = top[0], u = top[1], v = top[2];
            if (ds.find(u) != ds.find(v)) {
                ans += c;
                cnt++;
                ds.merge(u, v);
            }
        }

        return ans;
    }
}
