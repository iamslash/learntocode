// Copyright (C) 2020 by iamslash

import java.util.*;

// iterative dynamic programming
// O(HW) O(1)
class Solution {
	public int maximalSquare(char[][] M) {
    if (M.length == 0 || M[0].length == 0)
      return 0;
		int h = M.length, w = M[0].length, ans = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				M[y][x] -= '0';
				int a = 0, b = 0, c = 0;
				if (y > 0 && x > 0)
					a = M[y-1][x-1];
				if (y > 0)
					b = M[y-1][x];
				if (x > 0)
					c = M[y][x-1];
				if (M[y][x] > 0)
					M[y][x] = (char)(Math.min(a, Math.min(b, c)) + 1);
				ans = Math.max(ans, M[y][x] * M[y][x]);
			}
		}
		return ans;
	}
}
