// Copyright (C) 2020 by iamslash
import java.util.Queue;
import java.util.ArrayDeque;

// 3ms 81.83% 39.5MB 81.25%
// BFS
// O(N) O(N)
class Solution {
	private int[] ds = new int[]{-1, 0, 1, 0, -1};
	public int orangesRotting(int[][] G) {
		int cntFresh = 0, h = G.length, w = G[0].length;
		Queue<Integer> bfsq = new ArrayDeque<>();
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (G[y][x] == 1)
					cntFresh++;
				if (G[y][x] == 2) {
					bfsq.offer(y * 100 + x);
				}
			}
		}
		if (cntFresh == 0)
			return 0;
		// BFS loop
		int cnt = 0;        
		while (!bfsq.isEmpty()) {
			cnt++;			
			int n = bfsq.size();
			for (int i = 0; i < n; i++) {
				int front = bfsq.poll();
				int y = front / 100;
				int x = front % 100;
				for (int j = 0; j < 4; j++) {
					int ny = y + ds[j];
					int nx = x + ds[j+1];
					if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
							G[ny][nx] == 0 || G[ny][nx] == 2)
						continue;
					cntFresh--;
					G[ny][nx] = 2;
					bfsq.offer(ny * 100 + nx); 
				}
			}
		}
		return cntFresh == 0 ? cnt-1 : -1;
	}
}
