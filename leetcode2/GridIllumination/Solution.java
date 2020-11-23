// Copyright (C) 2020 by iamslash

import java.util.*;

// 74ms 67.23% 52.8MB 93.79%
// hash map
// O(N) O(N)
class Solution {
	private int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,0}};
	public int[] gridIllumination(int N, int[][] L, int[][] Q) {
		Map<Integer, Integer> rowCntMap = new HashMap<>();  // {row number: count of lamps}
		Map<Integer, Integer> colCntMap = new HashMap<>();  // {col number: count of lamps}
		Map<Integer, Integer> posDagCntMap = new HashMap<>(); // {diagonal x-y: count of lamps}
		Map<Integer, Integer> negDagCntMap = new HashMap<>(); // {diagonal x+y: count of lamps}
		Map<Integer, Boolean> turnOnMap = new HashMap<>();    // {lamp: turn on|off}

		// Increment counts while adding lamps
		for (int i = 0; i < L.length; ++i) {
			int y = L[i][0];
			int x = L[i][1];
			rowCntMap.put(y, rowCntMap.getOrDefault(y, 0) + 1);
			colCntMap.put(x, colCntMap.getOrDefault(x, 0) + 1);
			negDagCntMap.put(y-x, negDagCntMap.getOrDefault(y-x, 0) + 1);
			posDagCntMap.put(y+x, posDagCntMap.getOrDefault(y+x, 0) + 1);
			turnOnMap.put(y * N + x, true);
		}
		int[] ans = new int[Q.length];
		// Check queries
		for (int i = 0; i < Q.length; ++i) {
			int y = Q[i][0];
			int x = Q[i][1];

			ans[i] = 0;
			if (rowCntMap.getOrDefault(y, 0) > 0 ||
					colCntMap.getOrDefault(x, 0) > 0 ||
					negDagCntMap.getOrDefault(y-x, 0) > 0 ||
					posDagCntMap.getOrDefault(y+x, 0) > 0) {
			 ans[i] = 1;
			}

			// Switch off lamps
			for (int d = 0; d < dirs.length; ++d) {
				int ny = y + dirs[d][0];
				int nx = x + dirs[d][1];
				if (turnOnMap.containsKey(ny * N + nx) &&
						turnOnMap.get(ny * N + nx)) {
					rowCntMap.put(ny, rowCntMap.getOrDefault(ny, 1) - 1);
					colCntMap.put(nx, colCntMap.getOrDefault(nx, 1) - 1);
					negDagCntMap.put(ny-nx, negDagCntMap.getOrDefault(ny-nx, 1) - 1);
					posDagCntMap.put(ny+nx, posDagCntMap.getOrDefault(ny+nx, 1) - 1);
					turnOnMap.put(ny * N + nx, false);
				}
			}
		}
		return ans;
	}
}
