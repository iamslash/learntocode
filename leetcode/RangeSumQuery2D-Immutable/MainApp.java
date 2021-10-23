// Copyright (C) 2021 by iamslash

import java.util.*;

// 3 0 1 4 2     3  3  4  8 10
// 5 6 3 2 1     8 14 18 24
// 1 2 0 1 5     9
// 4 1 0 1 7    13
// 1 0 3 0 5    14

// 201ms 26.98% 130.1MB 22.71%
// grid sum
// O(HW) O(1)
class NumMatrix {
	
	private int[][] gs;
	public NumMatrix(int[][] matrix) {
		int h = matrix.length, w = matrix[0].length;		
		gs = matrix;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {				
				if (y > 0) {
					gs[y][x] += gs[y-1][x];
				}
				if (x > 0) {
					gs[y][x] += gs[y][x-1];
				}
				if (y > 0 && x > 0) {
					gs[y][x] -= gs[y-1][x-1];
				}
			}
		}
	}
  
	public int sumRegion(int y, int x, int z, int w) {
		int sum = gs[z][w];
		if (x > 0) {
			sum -= gs[z][x-1];
		}
		if (y > 0) {
			sum -= gs[y-1][w];
		}
		if (y > 0 && x > 0) {
			sum += gs[y-1][x-1];
		}
		return sum;
	}
}


public class MainApp {
  public static void main(String[] args) {
  }
}
