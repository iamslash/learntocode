// Copyright (C) 2020 by iamslash

import java.util.*;

// G: 10  5
//    10 -5
//
// M:  1  1  M
//     1  6  1
//     M  1  M

// G: -2  -3  3 
//    -5 -10  1 
//    10  30 -5 

// C:  7   5  2 M
//     6  11  5 M
//     1   1  6 1
//     M   M  1 M

// 1ms 94.01% 39.8MB 44.42%
// dynamic programming
// O(HW) O(HW)
class Solution {
	public int calculateMinimumHP(int[][] D) {
		int h = D.length, w = D[0].length;
		int[][] C = new int[h+1][w+1];		
		for (int y = 0; y <= h; ++y) {
			Arrays.fill(C[y], Integer.MAX_VALUE);
		}
		C[h][w-1] = 1; C[h-1][w] = 1;
		for (int y = h-1; y >= 0; --y) {
			for (int x = w-1; x >= 0; --x) {
				int hp = Math.min(C[y+1][x], C[y][x+1]) - D[y][x];
				if (hp <= 0)
					hp = 1;
				C[y][x] = hp;
			}
		}
		return C[0][0];
	}
}
