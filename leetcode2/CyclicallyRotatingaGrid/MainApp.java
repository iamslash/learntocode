// Copyright (C) 2021 by iamslash

import java.util.*;


//      h: 6
//      w: 4
// layers: 2 min(4,6)/2
// cnt of elements in the layer
//       : (h-1 - 2*i + w-1 - 2*i) * 2
//
// 1   2  3  4
// 16  1  2  5
// 15  8  3  6
// 14  7  4  7
// 13  6  5  8
// 12 11 10  9

//  2  3  4  5
//  1  2  3  6
// 16  1  4  7
// 15  8  5  8
// 14  7  6  9
// 13 12 11 10

// 7ms 43.63 % 39.5MB 95.03%
// brute force
// O(HW) O(1)
class Solution {
	public int[][] rotateGrid(int[][] grid, int k) {
		int h = grid.length, w = grid[0].length;
		// loop each layer
		for (int i = 0; i < h/2 && i < w/2; ++i) {
			// k % count of elements in i layer
			int cnt = k % ((h-1-2*i + w-1-2*i) * 2);
			while (cnt-- > 0) {
				// save left top
				int t = grid[i][i];
				// top
				for (int j = i; j < w-1-i; ++j) {
					grid[i][j] = grid[i][j+1];
				}
				// right
				for (int j = i; j < h-1-i; ++j) {
					grid[j][w-1-i] = grid[j+1][w-1-i];
				}
				// bottom
				for (int j = w-1-i; j > i; --j) {
					grid[h-1-i][j] = grid[h-1-i][j-1];
				}
				// left
				for (int j = h-1-i; j > i; --j) {
					grid[j][i] = grid[j-1][i];
				}
				// fill left top-1
				grid[i+1][i] = t;
			}
		}
		return grid;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
