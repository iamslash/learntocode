// Copyright (C) 2020 by iamslash

import java.util.*;

// 222ms 13.63% 215.7MB 5.68%
// dijkstra algorithm
// O(VlgV) O(V)
class Solution {
	public int reachableNodes(int[][] E, int M, int N) {
		int[][] G = new int[N][N];
		for (int i = 0; i < N; ++i) {
			Arrays.fill(G[i], -1);
		}
		for (int[] e : E) {
			int u = e[0], v = e[1];
			G[u][v] = e[2];
			G[v][u] = e[2];
		}
		int ans = 0;
		Queue<int[]> pq = new PriorityQueue<>((a, b) -> (b[1] - a[1]));
		boolean[] visit = new boolean[N];
		pq.offer(new int[]{0, M});
		while (pq.isEmpty() == false) {
			int[] item = pq.poll();
			int u = item[0];
			int cap = item[1];
			if (visit[u]) {
				continue;
			}
			visit[u] = true;
			ans++;
			for (int v = 0; v < N; v++) {
				if (G[u][v] == -1) {
					continue;
				}
				if (cap > G[u][v] && visit[v] == false) {
					pq.offer(new int[]{v, cap - G[u][v] - 1});
				}
				int minMove = Math.min(cap, G[u][v]);
				G[v][u] -= minMove;
				ans += minMove;
			}
		}
		return ans;
	}
}
