// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 33.33% 39.1MB 33.33%
// matrix
// O(N^2) O(N^2)
class Solution {
	private void printOrg(int[][] org) {
		int n = org.length;
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				System.out.printf("%d ", org[y][x]);
			}
			System.out.println();
		}
	}
	private int[][] rotate(int[][] mat) {
		int n = mat.length;
		int[][] tmp = new int[n][n];
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				tmp[y][x] = mat[x][n-y-1];
			}
		}
		return tmp;
	}
	private boolean compare(int[][] mat, int[][] tgt) {
		int n = tgt.length;
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				if (mat[y][x] != tgt[y][x]) {
					return false;
				}
			}
		}
		return true;
	}
	public boolean findRotation(int[][] mat, int[][] tgt) {
		for (int i = 0; i < 4; ++i) {
			mat = rotate(mat);
			if (compare(mat, tgt)) {
				return true;
			}
		}
		return false;
	}
}

// 1ms 33.33% 38.2MB 100.00%
// matrix
// O(N^2) O(1)
class Solution {
	public boolean findRotation(int[][] mat, int[][] tgt) {
		// compare result for 0, 90, 180, 270 rotation
		boolean result[] = new boolean[]{true, true, true, true};
		int n = mat.length;
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				if (mat[y][x] != tgt[y][x]) {
					result[0] = false;
				}
				if (mat[y][x] != tgt[n-x-1][y]) {
					result[1] = false;
				}
				if (mat[y][x] != tgt[n-y-1][n-x-1]) {
					result[2] = false;
				}
				if (mat[y][x] != tgt[x][n-y-1]) {
					result[3] = false;
				}
			}
		}
		return result[0] || result[1] || result[2] || result[3];
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
