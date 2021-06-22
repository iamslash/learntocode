// Copyright (C) 2021 by iamslash

import java.util.*;

// 22ms 90.56% 84.5MB 81.70%
// DFS
// O(HW) O(HW)
class Solution {
	private int[] dir = new int[] {-1, 0, 1, 0, -1};
	private void dfs(int[][] B, int y, int x, int c) {
		int h = B.length, w = B[0].length;
		B[y][x] = c;
		// recursion
		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[i];
			int nx = x + dir[i+1];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w || B[ny][nx] == c) {
				continue;
			}
			dfs(B, ny, nx, c);
		}
	}
	public int countSubIslands(int[][] A, int[][] B) {
		int h = A.length, w = A[0].length;
		// cover B with 0 color
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (A[y][x] == 0 && B[y][x] == 1) {
					dfs(B, y, x, 0);
				}
			}
		}
		// count B
		int cnt = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (B[y][x] == 1) {
					dfs(B, y, x, 0);
					cnt++;
				}
			}
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
