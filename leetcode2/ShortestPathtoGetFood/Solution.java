// Copyright (C) 2021 by iamslash

import java.util.*;

// 12ms 100.00% 47MB 100.00%
// BFS
// O(N) O(N)
class Solution {
	public int getFood(char[][] G) {
		int h = G.length, w = G[0].length;
		Queue<Integer> bfsq = new ArrayDeque<>();
		HashSet<Integer> visit = new HashSet<>();
		int[] dir = new int[]{-1, 0, 1, 0, -1};
		Integer startPos = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (G[y][x] == '*') {
					startPos = y * 200 + x;
					break;
				}
			}
		}
		bfsq.offer(startPos);
		int step = 0;
		while (!bfsq.isEmpty()) {
			int n = bfsq.size();
			for (int i = 0; i < n; ++i) {
				Integer u = bfsq.poll();
				int y = u / 200;
				int x = u % 200;
				if (G[y][x] == '#') {
					return step;
				}
				visit.add(u);
				for (int d = 0; d < 4; ++d) {
					int ny = y + dir[d];
					int nx = x + dir[d+1];
					int nu = ny * 200 + nx; 
					if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
              G[ny][nx] == 'X' || visit.contains(nu)) {
						continue;
					}
					visit.add(nu);
					bfsq.offer(nu);
				}
			}
			step++;
		}
		return -1;
	}
}
