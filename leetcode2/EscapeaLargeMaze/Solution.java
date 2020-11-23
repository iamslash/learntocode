// Copyright (C) 2020 by iamslash

// return false 
// when source is surrounding with blocks
// when target is surrounding with blocks

import java.util.*;

// 0 1 0 1
// 0 0 1 0
//       
//       

// 451ms 21.09% 57.7MB 37.41%
// BFS
// O(HW) O(HW)
class Solution {
	private Set<String> blocks = new HashSet<>();
	private int[] dir = new int[]{-1, 0, 1, 0, -1};

	public boolean isEscapePossible(int[][] B, int[] S, int[] T) {
		if (B.length == 0)
			return true;
		for (int[] block : B) {
			blocks.add(block[0] + "_" + block[1]);
		}
		return bfs(new HashSet<>(), S, T) &&
				bfs(new HashSet<>(), T, S);				
	}

	private boolean bfs(Set<String> visit, int[] S, int[] T) {
		int h = 1000000, w = 1000000;
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[]{S[0], S[1]});
		int lvl = blocks.size();
		while (q.isEmpty() == false && lvl-- >= 0) {
			int qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				int[] u = q.poll();
				int y = u[0], x = u[1];
				String k = y + "_" + x;
				if (y == T[0] && x == T[1])
					return true;
				for (int j = 0; j < 4; ++j) {
					int ny = y + dir[j];
					int nx = x + dir[j+1];
					String nk = ny + "_" + nx;
					if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
							blocks.contains(nk) || visit.contains(nk)) {
						continue;
					}
					visit.add(nk);
					q.offer(new int[]{ny, nx});
				}
			}			
		}
		return !q.isEmpty();
	}
}
