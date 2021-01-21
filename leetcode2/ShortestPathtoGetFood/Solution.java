// Copyright (C) 2021 by iamslash

// BFS
// O(N) O(N)
class Solution {
	public int getFood(char[][] G) {
		int h = G.length, w = G[0].length;
		Queue<Integer> bfsq = new ArrayDeque<>();
		HashSet<Integer> visit = new HashSet<>();
		Integer startPos = 0;
		for (y = 0; y < h; ++y) {
			for (x = 0; x < w; ++x) {
				if (G[y][x] == '*') {
					startPos = y * 200 + x;
					break;
				}
			}
		}
		bfsq.offer(startPos);
		while (!bfsq.isEmpty()) {
		}
		return -1;
	}
}
