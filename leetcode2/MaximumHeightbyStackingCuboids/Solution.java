// Copyright (C) 2020 by iamslash

import java.util.*;

// 8ms 49.06% 39.4MB 36.90%
// iterative dynamic programming
// O(N^2) O(N^2)
class Solution {
	public int maxHeight(int[][] A) {
		for (int[] a : A) {
			Arrays.sort(a);
		}
		Arrays.sort(A, (a, b) -> {
				if (a[0] != b[0])
					return a[0] - b[0];
				if (a[1] != b[1])
					return a[1] - b[1];
				return a[2] - b[2];
			});
		int n = A.length, ans = 0;
		int[] C = new int[n];
		for (int j = 0; j < n; ++j) {
			C[j] = A[j][2];
			for (int i = 0; i < j; ++i) {
				if (A[i][0] <= A[j][0] &&
						A[i][1] <= A[j][1] &&
						A[i][2] <= A[j][2]) {
					C[j] = Math.max(C[j], C[i] + A[j][2]);
				}
			}
			ans = Math.max(ans, C[j]);
		}
		return ans;
	}
}
