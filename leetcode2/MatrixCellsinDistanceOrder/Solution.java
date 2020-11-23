// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 13ms 65.81% 41.8MB 18.18%
// sort
// O(NlgN) O(N)
class Solution {
	private int getDist(int a, int b, int c, int d) {
		return Math.abs(a-c) + Math.abs(b-d);
	}
	public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
		int[][] cells = new int[R*C][2];
		for (int y = 0; y < R; ++y) {
			for (int x = 0; x < C; ++x) {
				cells[y * C + x][0] = y;
				cells[y * C + x][1] = x;
			}
		}
		Arrays.sort(cells,
								(a, b) ->
								Integer.valueOf(getDist(a[0], a[1], r0, c0))
								.compareTo(getDist(b[0], b[1], r0, c0)));
		return cells;		
	}
}
