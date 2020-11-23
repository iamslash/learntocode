// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// // 1ms 12.69% 37.2MB 100.00%
// // math
// // O(1) O(1)
// class Solution {
// 	private double getSlope(int a, int b, int c, int d) {
// 		return (double)(c - a) / (d - b);
// 	}
// 	public boolean isBoomerang(int[][] P) {
// 		Arrays.sort(P, (a, b) -> {
// 				if (a[0] == b[0])
// 					return Integer.valueOf(a[1]).compareTo(b[1]);
// 				return Integer.valueOf(a[0]).compareTo(b[0]);
// 			});
// 		for (int i = 1; i < 3; ++i) {
// 			if (P[i-1][0] == P[i][0] && P[i-1][1] == P[i][1])
// 				return false;
// 		}
// 		return getSlope(P[0][0], P[0][1], P[1][0], P[1][1])
// 				!= getSlope(P[1][0], P[1][1], P[2][0], P[2][1]);
// 	}
// }

// (1, 1) (2, 2) (3, 3)
// (2 - 1) / (2 - 1) != (2 - 3) / (2 - 3)

// slopeAB != slope AC
// (x0 - x1) / (y0 - y1) != (x0 - x2) / (y0 - y2)
// (x0 - x1) * (y0 - y2) != (x0 - x2) * (y0 - y1)

// 0ms 100.00% 37.1MB 100.00%
// math
// O(1) O(1)
class Solution {
	public boolean isBoomerang(int[][] P) {
		return (P[0][0] - P[1][0]) * (P[0][1] - P[2][1]) !=
				(P[0][0] - P[2][0]) * (P[0][1] - P[1][1]);
	}
}
