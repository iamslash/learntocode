// Copyright (C) 2020 by iamslash

// 12ms 28.30% 53.3MB 5.02%
// back tracking
class Solution {
	private boolean dfs(char[][]B, String s, int y, int x, int i) {
		int h = B.length, w = B[0].length;
		// base
		if (B[y][x] != s.charAt(i))
			return false;
		if (i+1 >= s.length())
			return true;
		// recursion
		int ds[] = {-1, 0, 1, 0, -1};
		for (int j = 0; j < 4; ++j) {
			int ny = y + ds[j];
			int nx = x + ds[j+1];
			B[y][x] ^= 256;
			if (ny >= 0 && ny < h && nx >= 0 && nx < w &&
					B[ny][nx] > 0 && dfs(B, s, ny, nx, i+1))
				return true;
			B[y][x] ^= 256;
		}
		return false;
	}
	public boolean exist(char[][] B, String s) {
		int h = B.length, w = B[0].length;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (dfs(B, s, y, x, 0))
					return true;
			}
		}
		return false;
	}
}
