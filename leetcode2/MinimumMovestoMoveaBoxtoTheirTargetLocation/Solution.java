// Copyright (C) 2020 by iamslash

import java.util.*;

// 217ms 8.86% 88.4MB 5.70%
// double BFS
// O(HW) O(HW)
class Solution {
	private int[] dirs = new int[]{-1, 0, 1, 0, -1};
	private int encode(int by, int bx, int sy, int sx) {
		return (by << 24) | (bx << 16) | (sy << 8) | sx;
	}
	private int[] decode(int state) {
		int[] ans = new int[4];
		ans[0] = (state >>> 24) & 0xFF;
		ans[1] = (state >>> 16) & 0xFF;
		ans[2] = (state >>> 8) & 0xFF;
		ans[3] = state & 0xFF;
		return ans;
	}
	public int minPushBox(char[][] G) {
		int[] B = new int[2], T = new int[2], S = new int[2];
		int h = G.length, w = G[0].length;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (G[y][x] == 'B') {
					B[0] = y;
					B[1] = x;
				} else if (G[y][x] == 'T') {
					T[0] = y;
					T[1] = x;
				} else if (G[y][x] == 'S') {
					S[0] = y;
					S[1] = x;
				}
			}
		}
		Queue<Integer> q = new LinkedList<>();
		Map<Integer, Integer> dist = new HashMap<>();
		int start = encode(B[0], B[1], S[0], S[1]);
		dist.put(start, 0);
		q.offer(start);
		int ans = Integer.MAX_VALUE;
		while (q.isEmpty() == false) {
			int eU = q.poll();
			int[] dU = decode(eU);
			if (dist.get(eU) >= ans)
				continue;
			if (dU[0] == T[0] && dU[1] == T[1]) {
				ans = Math.min(ans, dist.get(eU));
				continue;
			}
			int[] bPos = new int[]{dU[0], dU[1]};
			int[] sPos = new int[]{dU[2], dU[3]};
			for (int d = 0; d < 4; d++) {
				int nsy = sPos[0] + dirs[d];
				int nsx = sPos[1] + dirs[d+1];
				if (nsy < 0 || nsy >= h || nsx < 0 || nsx >= w ||
						G[nsy][nsx] == '#')
					continue;
				if (nsy == bPos[0] && nsx == bPos[1]) {
					// Move box
					int nby = bPos[0] + dirs[d];
					int nbx = bPos[1] + dirs[d+1];
					if (nby < 0 || nby >= h || nbx <0 || nbx >= w ||
							G[nby][nbx] == '#')
						continue;
					int eV = encode(nby, nbx, nsy, nsx);
					if (dist.containsKey(eV) &&
							dist.get(eV) <= dist.get(eU) + 1)
						continue;
					dist.put(eV, dist.get(eU) + 1);
					q.offer(eV);
				} else {
					// Move worker
					int eV = encode(bPos[0], bPos[1], nsy, nsx);
					if (dist.containsKey(eV) &&
							dist.get(eV) <= dist.get(eU))
						continue;
					dist.put(eV, dist.get(eU));
					q.offer(eV);
				}
			}
		}
		return ans == Integer.MAX_VALUE ? -1 : ans;
	}
}
