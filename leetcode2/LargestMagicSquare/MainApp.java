// Copyright (C) 2021 by iamslash

import java.util.*;

// 7 1 4 5 6
// 2 5 1 6 4
// 1 5 3 3 2
// 1 2 7 3 4

// 5ms 87.29% 39.5MB 43.06%
// prefix sum
// O(H^2W^2) O(HW)
class Solution {
	public int largestMagicSquare(int[][] grid) {
		int h = grid.length, w = grid[0].length, maxLen = 0;
		int[][] rows = new int [h+2][w+2];
		int[][] cols = new int [h+2][w+2];
		int[][] dia1 = new int [h+2][w+2];
		int[][] dia2 = new int [h+2][w+2];
		// build prefix sum
		for (int y = 1; y <= h; ++y) {
			for (int x = 1; x <= w; ++x) {
				rows[y][x] += rows[y][x-1]   + grid[y-1][x-1]; 
				cols[y][x] += cols[y-1][x]   + grid[y-1][x-1];
				dia1[y][x] += dia1[y-1][x-1] + grid[y-1][x-1];
				dia2[y][x] += dia2[y-1][x+1] + grid[y-1][x-1];
			}
		}
		// Find max magic square
		for (int y = 1; y <= h; ++y) {
			for (int x = 1; x <= w; ++x) {
				for (int k = Math.min(h-y, w-x); k > maxLen; --k) {
					// check dia1, dia2
					int sum = dia1[y+k][x+k] - dia1[y-1][x-1];
					boolean match = sum == dia2[y+k][x] - dia2[y-1][x+k+1];
					// check every rows, cols
					for (int l = 0; l <= k && match; ++l) {
						match &= sum == rows[y+l][x+k] - rows[y+l][x-1];
						match &= sum == cols[y+k][x+l] - cols[y-1][x+l];
					}
					maxLen = match ? k : maxLen;
				}
			}
		}
		return maxLen + 1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
