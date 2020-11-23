// Copyright (C) 2020 by iamslash

import java.util.*;

// 127ms 26.37% 63.9MB 11.91%
// BFS
// O(HW) O(HW)
class Solution {
	class State {
		int keys, y, x;
		State(int keys, int y, int x) {
			this.keys = keys;
			this.y = y;
			this.x = x;
		}
	}
	public int shortestPathAllKeys(String[] G) {
		int sy = -1, sx = -1, h = G.length, w = G[0].length(), maxKey = -1;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				char c = G[y].charAt(x);
				if (c == '@') {
					sy = y;
					sx = x;
				}
				if (c >= 'a' && c <= 'f') {
					maxKey = Math.max(maxKey, c-'a'+1);
				}
			}
		}
		int endKeys = (1 << maxKey) - 1;
		State start = new State(0, sy, sx);
		Queue<State> q = new LinkedList<>();
		Set<String> visit = new HashSet();
		visit.add(0 + " " + sy + " " + sx);
		q.offer(start);
		int[] dir = new int[]{-1, 0, 1, 0, -1};
		int step = 0;
		while (q.isEmpty() == false) {
			int nq = q.size();
			while (nq-- > 0) {
				State u = q.poll();
				if (u.keys == endKeys) {
					return step;
				}
				for (int i = 0; i < 4; ++i) {
					int ny = u.y + dir[i];
					int nx = u.x + dir[i+1];
					int nkeys = u.keys;
					if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
						continue;
					}
					char c = G[ny].charAt(nx);
					if (c == '#') {
						continue;
					}
					if (c >= 'a' && c <= 'f') {
						nkeys |= 1 << (c - 'a');						
					}
					// Try open gates
					if (c >= 'A' && c <= 'F' &&
							(nkeys & (1 << (c - 'A'))) == 0) {
						continue;
					}
					String visitKey = nkeys + " " + ny + " " + nx;
					if (visit.contains(visitKey) == true) {
						continue;
					}
					visit.add(visitKey);
					q.offer(new State(nkeys, ny, nx));
				}
			}
			step++;
		}
		return -1;
	}
}
