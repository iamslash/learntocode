// Copyright (C) 2022 by iamslash

import java.util.*;

// 942ms 20.00% 118MB 40.00%
// dijkstra
// O(NlgN) O(N)
class Solution {
    private long dijkstra(List<List<int[]>> graph, int[] appleCost, int k, int start) {
        long ans = Long.MAX_VALUE;
        // {city, cost}
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        Set<Integer> visit = new HashSet<>();
        pq.offer(new int[]{start, 0});
        while (!pq.isEmpty()) {
            int size = pq.size();
            for (int i = 0; i < size; ++i) {
                int[] top = pq.poll();
                visit.add(top[0]);
                ans = Math.min(ans, top[1] * (k + 1L) + appleCost[top[0] - 1]);
                List<int[]> cities = graph.get(top[0]);
                for (int[] city : cities) {
                    if (!visit.contains(city[0])) {
                        pq.offer(new int[]{city[0], top[1] + city[1]});
                    }
                }
            }
        }
        return ans;
    }
    public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
        long[] ans = new long[n];
        List<List<int[]>> graph = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] road : roads) {
            int u = road[0], v = road[1], c = road[2];
            graph.get(u).add(new int[]{v, c});
            graph.get(v).add(new int[]{u, c});
        }
        for (int u = 1; u <= n; ++u) {
            ans[u - 1] = dijkstra(graph, appleCost, k, u);
        }
        return ans;
    }
}
