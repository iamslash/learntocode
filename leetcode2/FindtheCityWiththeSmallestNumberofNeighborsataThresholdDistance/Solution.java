// Copyright (C) 2020 by iamslash

// 10ms 90.19% 39.2MB 100.00%
// floyd algorithm
// O(V^3) O(V^2)
class Solution {
	public int findTheCity(int n, int[][] E, int distThreshold) {
		int[][] dist = new int[100][100];
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				dist[u][v] = u == v ? 0 : 10000;
			}
		}
		for (int[] e : E) {
			dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
		}
		for (int k = 0; k < n; ++k) {
			for (int u = 0; u < n; ++u) {
				for (int v = 0; v < n; ++v) {
					dist[u][v] = Math.min(dist[u][v], dist[u][k] + dist[k][v]);
				}
			}
		}
		int minCnt = n, minNode = 0;
		for (int u = 0; u < n; ++u) {
			int curCnt = 0;
			for (int v = 0; v < n; ++v) {
				if (u == v)
					continue;
				if (dist[u][v] <= distThreshold)
					curCnt++;
			}
			if (curCnt <= minCnt) {
				minNode = u;
				minCnt = curCnt;
			}
		}
		return minNode;
	}
}
