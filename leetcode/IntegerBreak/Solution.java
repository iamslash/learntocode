// Copyright (C) 2021 by iamslash

import java.util.*;

// // 0ms 100.00% 35.4MB 92.36%
// // recursive dynamic programming
// // O(N^2) O(N)
// class Solution {
// 	private int dfs(int[] C, int n) {
// 		// base
// 		if (n <= 2) {
// 			return 1;
// 		}
// 		// memo
// 		if (C[n] >= 1) {
// 			return C[n];
// 		}
// 		// recursion
// 		for (int i = 1; i < n; ++i) {
// 			C[n] = Math.max(C[n],
// 											Math.max(i * (n-i), i * dfs(C, n - i)));
// 		}
// 		return C[n];
// 	}
// 	public int integerBreak(int n) {
// 		int[] C = new int[n+1];
// 		Arrays.fill(C, -1);
// 		C[0] = 1;
// 		C[1] = 1;
// 		return dfs(C, n);
// 	}
// }

// 1ms 51.02% 35.8MB 57.39%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
	public int integerBreak(int n) {
		int[] C = new int[n+1];
		C[0] = 1; C[1] = 1; C[2] = 1;
		for (int a = 3; a <= n; ++a) {
			for (int i = 1; i < a; ++i) {
				C[a] = Math.max(C[a], Math.max(i * (a-i), i * C[a-i]));
        // System.out.printf("a: %d, i: %d, C[a]: %d\n", a, i, C[a]);
			}
		}
		return C[n];
	}
}
