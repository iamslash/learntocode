// Copyright (C) 2022 by iamslash

import java.util.*;

// 143ms 65.16% 68MB 26.64%
// dijkstra
// O(ElgV) O(V)
class Solution {
    public int minimumCost(int n, int[][] highways, int discounts) {
        // Build graph
        List<int[]>[] G = new List[n];
        for (int u = 0; u < n; ++u) {
            G[u] = new ArrayList<>();
        }
        for (int[] item : highways) {
            int u = item[0], v = item[1], c = item[2];
            G[u].add(new int[]{v, c});
            G[v].add(new int[]{u, c});
        }
        // [cost, dst, discount]
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});
        int[][] dist = new int[n][discounts+1];
        for (int u = 0; u < n; ++u) {
            Arrays.fill(dist[u], Integer.MAX_VALUE);
        }
        dist[0][0] = 0;
        // dijkstra loop
        while (!pq.isEmpty()) {
            int[] uItem = pq.poll();
            int dist2u = uItem[0], u = uItem[1], discount2u = uItem[2];
            if (u == n-1) {
                return dist2u;
            }
            // Traverse neighbors
            for (int[] vItem : G[u]) {
                int v = vItem[0], dist2v = vItem[1];
                // When not use discount
                if (dist2u + dist2v < dist[v][discount2u]) {
                    pq.offer(new int[]{dist2u + dist2v, v, discount2u});
                    dist[v][discount2u] = dist2u + dist2v;
                }
                // When use discount
                if (discount2u < discounts &&
                    dist2u + dist2v / 2 < dist[v][discount2u + 1]) {
                    pq.offer(new int[]{dist2u + dist2v / 2, v, discount2u + 1});
                    dist[v][discount2u + 1] = dist2u + dist2v / 2;
                }
            }
        }
        return -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
