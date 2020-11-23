// Copyright (C) 2020 by iamslash

import java.util.*;


// 6ms 82.97% 40MB 5.64%
// dijkstra algorithm
// O(ElgV) O(V)
class Solution {
	public int findCheapestPrice(int n, int[][] F, int src, int dst, int K) {
		int[][] G = new int[n][n];
		for (int[] flight : F) {
			int u = flight[0];
			int v = flight[1];
			int d = flight[2];
			G[u][v] = d;
		}
		Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
		pq.add(new int[]{0, src, K+1});
		while (pq.size() > 0) {
			int[] top = pq.poll();
			int dist = top[0], u = top[1], ttl = top[2];
			if (u == dst)
				return dist;
			if (ttl <= 0)
				continue;
			for (int v = 0; v < n; ++v) {
				if (G[u][v] == 0)
					continue;
				pq.add(new int[]{G[u][v] + dist, v, ttl - 1});
			}
		}
		return -1;
	}
}
