// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36.9MB 13.33%
// bruteforce
// O(HW) O(1)
class Solution {
	private int getPawns(char[][] B, int y, int x, int dy, int dx) {
		while (y >= 0 && y < B.length && x >= 0 && x < B[0].length &&
					 B[y][x] != 'B') {
			if (B[y][x] == 'p')
				return 1;
			y += dy;
			x += dx;
		}
		return 0;
	}
	public int numRookCaptures(char[][] B) {
		for (int y = 0; y < B.length; ++y) {
			for (int x = 0; x < B[0].length; ++x) {
				if (B[y][x] == 'R')
					return getPawns(B, y, x, -1, 0) +
							getPawns(B, y, x, 0, 1) +
							getPawns(B, y, x, 1, 0) +
							getPawns(B, y, x, 0, -1);
			}
		}
		return 0;
	}
}
