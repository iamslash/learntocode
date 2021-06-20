// Copyright (C) 2021 by iamslash

// 2ms 25.27% 85.2MB 13.55%
// brute force
// O(HW) O(1)
class Solution {
	public int[] findPeakGrid(int[][] mat) {
		int maxNum = mat[0][0], maxY = 0, maxX = 0;
		int h = mat.length, w = mat[0].length;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (maxNum < mat[y][x]) {
					maxNum = mat[y][x];
					maxY = y;
					maxX = x;
				}
			}
		}
		return new int[]{maxY, maxX};
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
