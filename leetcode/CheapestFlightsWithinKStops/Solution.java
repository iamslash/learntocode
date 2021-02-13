// Copyright (C) 2021 by iamslash

import java.util.*;

// 6ms 81.47% 39.8MB 59.29%
// dijkstra algorithm
// O(N) O(N)
class Solution {
	public int findCheapestPrice(
			int n, int[][] flights,
			int src, int dst, int k) {
		int[][] G = new int[n][n];
		for (int[] f : flights) {
			G[f[0]][f[1]] = f[2];
		}
		// {distance, u, ttl}
		Queue<int[]> pq = new PriorityQueue<>((a, b) -> {
				return a[0] - b[0];
		});
		pq.offer(new int[]{0, src, k+1});		
		while (pq.size() > 0) {
			int[] item = pq.poll();
			int cost = item[0];
			int u = item[1];
			int ttl  = item[2];
			if (u == dst) {
				return cost;
			}
			if (ttl == 0) {
				continue;
			}
			// visit neighbors
			for (int v = 0; v < n; ++v) {
				if (G[u][v] == 0) {
					continue;
				}
				pq.offer(new int[]{cost + G[u][v], v, ttl-1});
			}
		}
		return -1;
	}
}
