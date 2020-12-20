// Copyright (C) 2020 by iamslash
import java.util.*;

// 3ms 91.35% 42.5MB 39.15%
// iterative dynamic programming
// O(HW) O(W)
class Solution {
	public int maximalRectangle(char[][] M) {
		if (M.length == 0 || M[0].length == 0) {
			return 0;
		}
		int ans = 0, h = M.length, w = M[0].length;
		int[] left = new int[w], right = new int[w], height = new int[w];
		Arrays.fill(right, w);
		for (int y = 0; y < h; ++y) {
			int curLeft = 0, curRight = w;
			// fill right[]
			for (int x = w-1; x >= 0; --x) {
				if (M[y][x] == '1') {
					right[x] = Math.min(right[x], curRight);
				} else {
					right[x] = w;
					curRight = x;
				}
			}
			// fill height[], left[]
			for (int x = 0; x < w; ++x) {
				if (M[y][x] == '1') {
					height[x]++;
					left[x] = Math.max(left[x], curLeft);
				} else {
					height[x] = 0;
					left[x] = 0;
					curLeft = x + 1;
				}				
				ans = Math.max(ans, (right[x]-left[x])*height[x]);
			}
		}
		return ans;
	}
}
