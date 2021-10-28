// Copyright (C) 2021 by iamslash

import java.util.*;

//               i
//    graph: 0 - 1 - 2
//     dist: 0   2   4
// patience: 0   2   1
// lastInTs: 0   2   7
//   idelTs:     3   8


//               i
//    graph: 0 - 1 - 2
//     dist: 0   2   4
// patience: 0   1   2
// lastInTs: 0   3   6
//   idelTs:     4   7

//
//    graph:
//               0
//             /   \
//            1 --- 2
//
//     dist: 0   2   2
// patience: 0  10  10
//   idleTs: 0   3   3


// lastInTs = dist + dist - (dist % patience) (dist % patience != 0)
// lastInTs = dist + dist - patience          (dist % patience == 0)

// Wrong Answer for:
// [[5,7],[15,18],[12,6],[5,1],[11,17],[3,9],[6,11],[14,7],[19,13],[13,3],[4,12],[9,15],[2,10],[18,4],[5,14],[17,5],[16,2],[7,1],[0,16],[10,19],[1,8]]
// [0,2,1,1,1,2,2,2,2,1,1,1,2,1,1,1,1,2,1,1]
//
// BFS
// O(E+V) O(N)
class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            adj.add(new ArrayList<>());
        }
        // build graph
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        // build dists with BFS
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        int[] dists = new int[n];
        Arrays.fill(dists, -1);
        dists[0] = 0;
        int lvl = 0;
        while (!q.isEmpty()) {
            lvl++;
            int size = q.size();
            while (size-- > 0) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (dists[v] == -1) {
                        q.offer(v);
                        dists[v] = 2 * lvl;
                    }
                }
            }
        }
        // calculate maxLastInTs
        int maxLastInTs = 0;
        for (int u = 0; u < n; ++u) {
            int dist = dists[u];
            int lastInTs = dist;
            if (dist > patience[u]) {
                lastInTs += dist - 1;
            }
            maxLastInTs = Math.max(maxLastInTs, lastInTs);
        }
        return maxLastInTs + 1;
    }
}

// 101ms 82.18% 95.8MB 70.54%
// BFS
// O(E+V) O(N)
class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            adj.add(new ArrayList<>());
        }
        // build graph
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        // build dists with BFS
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        int[] dists = new int[n];
        Arrays.fill(dists, -1);
        dists[0] = 0;
        int lvl = 0;
        while (!q.isEmpty()) {
            lvl++;
            int size = q.size();
            while (size-- > 0) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (dists[v] == -1) {
                        q.offer(v);
                        dists[v] = 2 * lvl;
                    }
                }
            }
        }
        // calculate maxLastInTs
        int maxLastInTs = 0;
        for (int u = 1; u < n; ++u) {
            int dist = dists[u];
            int lastInTs = dist + dist - (dist % patience[u]);
            if (dist % patience[u] == 0) {
                lastInTs -= patience[u];
            }
            maxLastInTs = Math.max(maxLastInTs, lastInTs);
        }
        return maxLastInTs + 1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
