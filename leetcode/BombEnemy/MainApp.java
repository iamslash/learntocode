// Copyright (C) 2021 by iamslash

import java.util.*;

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// brute force
// O(HW) O(W)
class Solution {
	public int maxKilledEnemies(char[][] G) {
		if (G.length == 0 || G[0].length == 0) {
			return 0;
		}		
		int h = G.length, w = G[0].length, glbMax = 0;
		int[] killCols = new int[w];
		int killRow = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (x == 0 || G[y][x-1] == 'W') {
					killRow = 0;
					for (int k = x; k < w && G[y][k] != 'W'; ++k) {
						if (G[y][k] == 'E') {
							killRow++;
						}
					}
				}
				if (y == 0 || G[y-1][x] == 'E') {
					killCols[x] = 0;
					for (int k = y; k < h && G[k][x] != 'W'; ++k) {
						if (G[k][x] == 'E') {
							killCols[x]++;
						}
					}
				}
				if (G[y][x] == '0') {
					glbMax = Math.max(glbMax, killRow + killCols[x]);
				}
			}
		}
		return glbMax;
	}
}

public class MainApp {
  public static void main(String[] args) {
		Solution sln = new Solution();
		// 1
		System.out.println(sln.maxKilledEnemies(new char[][]{{'W'},{'E'},{'W'},{'0'},{'E'},}));
		// 3
		System.out.println(sln.maxKilledEnemies(new char[][]{{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}}));
  }
}
